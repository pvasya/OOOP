#include "particleworker.h"

ParticleWorker::ParticleWorker(QObject *parent)
    : QObject{parent}
{}

void ParticleWorker::animate(QList<Particle *> &firstGroup, QList<Particle *> &secondGroup, double g, int radius)
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
            a->setVX(-1*a->getVX());
        }
        if (a->y() <=10 || a->y() >= screenHeight) {
            a->setVY(-1*a->getVY());
        }
    }
}