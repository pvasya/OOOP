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

        a->vx = (a->vx + fx) * 0.5;
        a->vy = (a->vy + fy) * 0.5;
        a->moveBy(a->vx, a->vy);
        if (a->x() <= 10 || a->x() >= screenWidth) {
            a->vx *= -1;
        }
        if (a->y() <= 10 || a->y() >= screenHeight) {
            a->vy *= -1;
        }
    }
}
