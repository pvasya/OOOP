#include "particlelifewidget.h"
#include "ui_particlelifewidget.h"
#include <QRandomGenerator>

ParticleLifeWidget::ParticleLifeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParticleLifeWidget)
{
    ui->setupUi(this);

    ui->graphicsView->setMouseTracking(true);

    animation = new QTimer(this);

    animation->start(1000/60);

    initialize();

    scene = new CustomScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //scene->setSceneRect(0,0,1500,1500);

    statemachine = new QStateMachine(this);

    init_state = new QState();
    play_state = new QState();
    pause_state = new QState();

    red_thread = new QThread();
    green_thread = new QThread();
    blue_thread = new QThread();

    connect(this, &QObject::destroyed, red_thread, &QThread::deleteLater);
    connect(this, &QObject::destroyed, green_thread, &QThread::deleteLater);
    connect(this, &QObject::destroyed, blue_thread, &QThread::deleteLater);


    particle_worker_red = new ParticleWorker();
    particle_worker_green = new ParticleWorker();
    particle_worker_blue = new ParticleWorker();

    connect(this,&ParticleLifeWidget::animateRed,particle_worker_red,&ParticleWorker::animation);
    connect(this,&ParticleLifeWidget::animateGreen,particle_worker_green,&ParticleWorker::animation);
    connect(this,&ParticleLifeWidget::animateBlue,particle_worker_blue,&ParticleWorker::animation);

    particle_worker_red->setLists(&redParticles,&greenParticles,&blueParticles);
    particle_worker_green->setLists(&greenParticles,&redParticles,&blueParticles);
    particle_worker_blue->setLists(&blueParticles,&greenParticles,&redParticles);


    particle_worker_red->moveToThread(red_thread);
    particle_worker_green->moveToThread(green_thread);
    particle_worker_blue->moveToThread(blue_thread);

    red_thread->start();
    green_thread->start();
    blue_thread->start();

    init_state->addTransition(ui->startBtn, &QPushButton::clicked, play_state);
    play_state->addTransition(ui->startBtn, &QPushButton::clicked, pause_state);
    pause_state->addTransition(ui->startBtn, &QPushButton::clicked, play_state);

    statemachine->addState(init_state);
    statemachine->addState(play_state);
    statemachine->addState(pause_state);
    statemachine->setInitialState(init_state);
    play_state->assignProperty(ui->multithreadBtn, "enabled", false);
    pause_state->assignProperty(ui->multithreadBtn, "enabled", true);
    pause_state->assignProperty(ui->generateRandomBtn, "enabled", true);
    play_state->assignProperty(ui->generateRandomBtn, "enabled", false);

    pause_state->assignProperty(ui->redSlider, "enabled", true);
    play_state->assignProperty(ui->redSlider, "enabled", false);
    pause_state->assignProperty(ui->greenSlider, "enabled", true);
    play_state->assignProperty(ui->greenSlider, "enabled", false);
    pause_state->assignProperty(ui->blueSlider, "enabled", true);
    play_state->assignProperty(ui->blueSlider, "enabled", false);

    play_state->assignProperty(ui->startBtn, "text", "Pause");
    pause_state->assignProperty(ui->startBtn, "text", "Resume");
    statemachine->start();

    mouse_pressed = false;
    particleFactory = new ParticleFactoryMethod();

    connect(animation, &QTimer::timeout, this, &ParticleLifeWidget::particleMovement);

    //connect(this, &ParticleLifeWidget::changePointP, move_to_mouse_worker, &MoveToMouseWorker::changePoint);

    connect(scene, &CustomScene::signalTargetCoordinate, this, &ParticleLifeWidget::toMouse);
    connect(scene, &CustomScene::press, this, &ParticleLifeWidget::pressM);
    connect(scene, &CustomScene::release, this, &ParticleLifeWidget::releaseM);

    /*
    connect(this, &ParticleLifeWidget::animateRed, [&]() {
        for (Particle* a : redParticles) {
            a->moveBy(a->getVX(), a->getVY());
        }
        loop.quit();
    });
    */


}

ParticleLifeWidget::~ParticleLifeWidget()
{
    delete ui;
}

void ParticleLifeWidget::toMouse(QPointF point)
{
    this->point = point;
}

void ParticleLifeWidget::pressM()
{
    mouse_pressed = true;
}

void ParticleLifeWidget::releaseM()
{
    mouse_pressed = false;
}

void ParticleLifeWidget::initialize()
{
    radius = ui->RedradiusSlider->value();
    red_count = ui->redSlider->value();
    green_count = ui->greenSlider->value();
    blue_count = ui->blueSlider->value();
    red_red = ui->redRedSlider->value();
    red_green = ui->redGreenSlider->value();
    red_blue = ui->redBlueSlider->value();
    green_red = ui->greenRedSlider->value();
    green_green = ui->greenGreenSlider->value();
    green_blue = ui->greenBlueSlider->value();
    blue_red = ui->blueRedSlider->value();
    blue_green = ui->blueGreenSlider->value();
    blue_blue = ui->blueBlueSlider->value();

}

void ParticleLifeWidget::animate(QList<Particle *> &firstGroup, QList<Particle *> &secondGroup, double g, int radius)
{
    int screenWidth = 1480;
    int screenHeight = 1480;

    for (auto it_a = firstGroup.begin(); it_a != firstGroup.end(); ++it_a) {
        double fx = 0;
        double fy = 0;
        Particle *a = *it_a;

        for (auto it_b = secondGroup.begin(); it_b != secondGroup.end(); ++it_b) {
            Particle *b = *it_b;
            int dx = a->x() - b->x();
            int dy = a->y() - b->y();
            double d = sqrt(dx * dx + dy * dy);

            if (d > 0 && d < radius) {
                double F = g / d;
                fx += (F * dx);
                fy += (F * dy);
            }
        }

        a->setVX((a->getVX() + fx) * 0.5);
        a->setVY((a->getVY() + fy) * 0.5);
        a->moveBy(a->getVX(), a->getVY());


        if(a->x() < 0){
            a->setPos(10,a->y());
        }
        if(a->x() > 1500){
            a->setPos(1480,a->y());
        }
        if(a->y() < 0){
            a->setPos(a->x(),10);
        }
        if(a->y() > 1500){
            a->setPos(a->x(),1480);
        }


        if (a->x() <= 10 || a->x() >= screenWidth) {
            a->setVX(a->getVX() * -1);
        }
        if (a->y() <=10 || a->y() >= screenHeight) {
            a->setVY(a->getVY() * -1);
        }
    }
}

void ParticleLifeWidget::animateToMouse(QPointF point)
{
    moveParticlesToTarget(redParticles, point);
    moveParticlesToTarget(greenParticles, point);
    moveParticlesToTarget(blueParticles, point);
}

void ParticleLifeWidget::moveParticlesToTarget(QList<Particle *> &particles, QPointF point)
{
    for (auto it = particles.begin(); it != particles.end(); ++it) {
        Particle *particle = *it;

        QPointF vectorToTarget = point - particle->pos();

        particle->setPos(particle->pos() + vectorToTarget/50);
    }
}

void ParticleLifeWidget::on_redSlider_valueChanged(int value)
{
    red_count = ui->redSlider->value();

    while (redParticles.count() < red_count) {
        Particle *newParticle = particleFactory->createParticle(
            QRandomGenerator::global()->bounded(10, 1450),
            QRandomGenerator::global()->bounded(10, 1450),
            "redSmall"
            );
        redParticles.append(newParticle);
        scene->addItem(newParticle);
    }

    while (redParticles.count() > red_count) {
        Particle *particle = redParticles.last();
        scene->removeItem(particle);
        redParticles.removeLast();
        delete particle;
    }
}



void ParticleLifeWidget::on_greenSlider_valueChanged(int value)
{
    green_count = ui->greenSlider->value();

    while (greenParticles.count() < green_count) {
        Particle *newParticle = particleFactory->createParticle(
            QRandomGenerator::global()->bounded(10, 1450),
            QRandomGenerator::global()->bounded(10, 1450),
            "greenSmall"
            );
        greenParticles.append(newParticle);
        scene->addItem(newParticle);
    }

    while (greenParticles.count() > green_count) {
        Particle *particle = greenParticles.last();
        scene->removeItem(particle);
        greenParticles.removeLast();
        delete particle;
    }
}


void ParticleLifeWidget::on_blueSlider_valueChanged(int value)
{
    blue_count = ui->blueSlider->value();

    while (blueParticles.count() < blue_count) {
        Particle *newParticle = particleFactory->createParticle(
            QRandomGenerator::global()->bounded(10, 1450),
            QRandomGenerator::global()->bounded(10, 1450),
            "blueSmall"
            );
        blueParticles.append(newParticle);
        scene->addItem(newParticle);
    }

    while (blueParticles.count() > blue_count) {
        Particle *particle = blueParticles.last();
        scene->removeItem(blueParticles.last());
        blueParticles.removeLast();
        delete particle;
    }
}

void ParticleLifeWidget::on_redRedSlider_valueChanged(int value)
{
    red_red = ui->redRedSlider->value();
}


void ParticleLifeWidget::on_redGreenSlider_valueChanged(int value)
{
    red_green = ui->redGreenSlider->value();
}


void ParticleLifeWidget::on_redBlueSlider_valueChanged(int value)
{
    red_blue = ui->redBlueSlider->value();
}


void ParticleLifeWidget::on_greenRedSlider_valueChanged(int value)
{
    green_red = ui->greenRedSlider->value();
}


void ParticleLifeWidget::on_greenGreenSlider_valueChanged(int value)
{
    green_green = ui->greenGreenSlider->value();
}


void ParticleLifeWidget::on_greenBlueSlider_valueChanged(int value)
{
    green_blue = ui->greenBlueSlider->value();
}


void ParticleLifeWidget::on_blueRedSlider_valueChanged(int value)
{
    blue_red = ui->blueRedSlider->value();
}


void ParticleLifeWidget::on_blueGreenSlider_valueChanged(int value)
{
    blue_green = ui->blueGreenSlider->value();
}


void ParticleLifeWidget::on_blueBlueSlider_valueChanged(int value)
{
    blue_blue = ui->blueBlueSlider->value();
}

void ParticleLifeWidget::on_generateRandomBtn_clicked()
{
    ui->RedradiusSlider->setValue(QRandomGenerator::global()->bounded(ui->RedradiusSlider->minimum(), ui->RedradiusSlider->maximum() + 1));
    ui->GreenradiusSlider->setValue(QRandomGenerator::global()->bounded(ui->GreenradiusSlider->minimum(), ui->GreenradiusSlider->maximum() + 1));
    ui->BlueradiusSlider->setValue(QRandomGenerator::global()->bounded(ui->BlueradiusSlider->minimum(), ui->BlueradiusSlider->maximum() + 1));
    ui->redSlider->setValue(QRandomGenerator::global()->bounded(ui->redSlider->minimum(), ui->redSlider->maximum() + 1));
    ui->greenSlider->setValue(QRandomGenerator::global()->bounded(ui->greenSlider->minimum(), ui->greenSlider->maximum() + 1));
    ui->blueSlider->setValue(QRandomGenerator::global()->bounded(ui->blueSlider->minimum(), ui->blueSlider->maximum() + 1));
    ui->redRedSlider->setValue(QRandomGenerator::global()->bounded(ui->redRedSlider->minimum(), ui->redRedSlider->maximum() + 1));
    ui->redGreenSlider->setValue(QRandomGenerator::global()->bounded(ui->redGreenSlider->minimum(), ui->redGreenSlider->maximum() + 1));
    ui->redBlueSlider->setValue(QRandomGenerator::global()->bounded(ui->redBlueSlider->minimum(), ui->redBlueSlider->maximum() + 1));
    ui->greenRedSlider->setValue(QRandomGenerator::global()->bounded(ui->greenRedSlider->minimum(), ui->greenRedSlider->maximum() + 1));
    ui->greenGreenSlider->setValue(QRandomGenerator::global()->bounded(ui->greenGreenSlider->minimum(), ui->greenGreenSlider->maximum() + 1));
    ui->greenBlueSlider->setValue(QRandomGenerator::global()->bounded(ui->greenBlueSlider->minimum(), ui->greenBlueSlider->maximum() + 1));
    ui->blueRedSlider->setValue(QRandomGenerator::global()->bounded(ui->blueRedSlider->minimum(), ui->blueRedSlider->maximum() + 1));
    ui->blueGreenSlider->setValue(QRandomGenerator::global()->bounded(ui->blueGreenSlider->minimum(), ui->blueGreenSlider->maximum() + 1));
    ui->blueBlueSlider->setValue(QRandomGenerator::global()->bounded(ui->blueBlueSlider->minimum(), ui->blueBlueSlider->maximum() + 1));
    initialize();
}

void ParticleLifeWidget::particleMovement()
{
    if(statemachine->configuration().contains(play_state)){
        if(mouse_pressed){
            animateToMouse(point);
        }

        if(ui->multithreadBtn->isChecked()){
            emit animateRed(-red_red/10,-red_green/10,-red_blue/10,ui->RedradiusSlider->sliderPosition());
            emit animateGreen(-green_green/10,-green_red/10,-green_blue/10,ui->GreenradiusSlider->sliderPosition());
            emit animateBlue(-blue_blue/10,-blue_green/10,-blue_red/10,ui->BlueradiusSlider->sliderPosition());
            /*
            animate(firstGroup,firstGroup,g1,radius);
            animate(firstGroup,secondGroup,g2,radius);
            animate(firstGroup,thirdGroup,g3,radius);
            */
            for (Particle* a : redParticles) {
                a->moveBy(a->getVX(), a->getVY());
                if(a->x() < 0){
                    a->setPos(10,a->y());
                }
                if(a->x() > 1500){
                    a->setPos(1480,a->y());
                }
                if(a->y() < 0){
                    a->setPos(a->x(),10);
                }
                if(a->y() > 1500){
                    a->setPos(a->x(),1480);
                }
            }
            for (Particle* a : greenParticles) {
                a->moveBy(a->getVX(), a->getVY());
                if(a->x() < 0){
                    a->setPos(10,a->y());
                }
                if(a->x() > 1500){
                    a->setPos(1480,a->y());
                }
                if(a->y() < 0){
                    a->setPos(a->x(),10);
                }
                if(a->y() > 1500){
                    a->setPos(a->x(),1480);
                }
            }
            for (Particle* a : blueParticles) {
                a->moveBy(a->getVX(), a->getVY());
                if(a->x() < 0){
                    a->setPos(10,a->y());
                }
                if(a->x() > 1500){
                    a->setPos(1480,a->y());
                }
                if(a->y() < 0){
                    a->setPos(a->x(),10);
                }
                if(a->y() > 1500){
                    a->setPos(a->x(),1480);
                }
            }


            /*
            particle_worker_red->animate(redParticles,redParticles,-red_red/10,ui->RedradiusSlider->sliderPosition());
            particle_worker_red->animate(redParticles,greenParticles,-red_green/10,ui->RedradiusSlider->sliderPosition());
            particle_worker_red->animate(redParticles,blueParticles,-red_blue/10,ui->RedradiusSlider->sliderPosition());
            particle_worker_green->animate(greenParticles,redParticles,-green_red/10,ui->GreenradiusSlider->sliderPosition());
            particle_worker_green->animate(greenParticles,greenParticles,-green_green/10,ui->GreenradiusSlider->sliderPosition());
            particle_worker_green->animate(greenParticles,blueParticles,-green_blue/10,ui->GreenradiusSlider->sliderPosition());
            particle_worker_blue->animate(blueParticles,redParticles,-blue_red/10,ui->BlueradiusSlider->sliderPosition());
            particle_worker_blue->animate(blueParticles,greenParticles,-blue_green/10,ui->BlueradiusSlider->sliderPosition());
            particle_worker_blue->animate(blueParticles,blueParticles,-blue_blue/10,ui->BlueradiusSlider->sliderPosition());
            */
        }
        else{
            animate(redParticles,redParticles,-red_red/10, ui->RedradiusSlider->sliderPosition());
            animate(redParticles,greenParticles,-red_green/10, ui->RedradiusSlider->sliderPosition());
            animate(redParticles,blueParticles,-red_blue/10, ui->RedradiusSlider->sliderPosition());
            animate(greenParticles,redParticles,-green_red/10, ui->GreenradiusSlider->sliderPosition());
            animate(greenParticles,greenParticles,-green_green/10, ui->GreenradiusSlider->sliderPosition());
            animate(greenParticles,blueParticles,-green_blue/10, ui->GreenradiusSlider->sliderPosition());
            animate(blueParticles,redParticles,-blue_red/10, ui->BlueradiusSlider->sliderPosition());
            animate(blueParticles,greenParticles,-blue_green/10, ui->BlueradiusSlider->sliderPosition());
            animate(blueParticles,blueParticles,-blue_blue/10, ui->BlueradiusSlider->sliderPosition());
        }
    }
}


