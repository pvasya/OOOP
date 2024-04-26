#ifndef PARTICLELIFEWIDGET_H
#define PARTICLELIFEWIDGET_H

#include "customscene.h"
#include "particleworker.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QtStateMachine/QStateMachine>
#include <QtStateMachine/QState>
#include <QThread>
#include <QTimer>
#include <QList>
#include "particle.h"
#include "particlefactorymethod.h"

namespace Ui {
class ParticleLifeWidget;
}

class ParticleLifeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParticleLifeWidget(QWidget *parent = nullptr);
    ~ParticleLifeWidget();

private slots:

    void toMouse(QPointF point);

    void pressM();

    void releaseM();

    void on_redSlider_valueChanged(int value);

    void on_greenSlider_valueChanged(int value);

    void on_blueSlider_valueChanged(int value);

    void on_redRedSlider_valueChanged(int value);

    void on_redGreenSlider_valueChanged(int value);

    void on_redBlueSlider_valueChanged(int value);

    void on_greenRedSlider_valueChanged(int value);

    void on_greenGreenSlider_valueChanged(int value);

    void on_greenBlueSlider_valueChanged(int value);

    void on_blueRedSlider_valueChanged(int value);

    void on_blueGreenSlider_valueChanged(int value);

    void on_blueBlueSlider_valueChanged(int value);

    void on_generateRandomBtn_clicked();

    void particleMovement();

private:
    Ui::ParticleLifeWidget *ui;

    void initialize();

    bool mouse_pressed;


    void animate(QList<Particle*>& firstGroup, QList<Particle*>& secondGroup, double g, int radius);

    int radius;
    int red_count;
    int green_count;
    int blue_count;
    int red_red;
    int red_green;
    int red_blue;
    int green_red;
    int green_green;
    int green_blue;
    int blue_red;
    int blue_green;
    int blue_blue;

    CustomScene *scene;

    QPointF point;

    void animateToMouse(QPointF point);
    void moveParticlesToTarget(QList<Particle*>& particles, QPointF point);

    QStateMachine* statemachine;
    QState* init_state;
    QState* play_state;
    QState* pause_state;

    ParticleWorker* particle_worker_red;
    ParticleWorker* particle_worker_green;
    ParticleWorker* particle_worker_blue;


    QThread* red_thread;
    QThread* green_thread;
    QThread* blue_thread;

    QTimer* animation;

    ParticleFactoryMethod* particleFactory;

    QList<Particle*> redParticles;
    QList<Particle*> greenParticles;
    QList<Particle*> blueParticles;



signals:
    animateRed(double g1,double g2,double g3, int radius);
    animateGreen(double g1,double g2,double g3, int radius);
    animateBlue(double g1,double g2,double g3, int radius);

};

#endif // PARTICLELIFEWIDGET_H
