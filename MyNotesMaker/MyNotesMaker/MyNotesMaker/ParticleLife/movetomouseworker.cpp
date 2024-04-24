#include "movetomouseworker.h"

#include <QWidget>

MoveToMouseWorker::MoveToMouseWorker(QObject *parent)
    : QObject{parent}
{
}

void MoveToMouseWorker::animateToMouse(QPointF point, QList<Particle *> &redParticles, QList<Particle *> &greenParticles, QList<Particle *> &blueParticles)
{
    moveParticlesToTarget(redParticles, point);
    moveParticlesToTarget(greenParticles, point);
    moveParticlesToTarget(blueParticles, point);
}

void MoveToMouseWorker::moveParticlesToTarget(QList<Particle *> &particles, QPointF point)
{
    for (auto it = particles.begin(); it != particles.end(); ++it) {
        Particle *particle = *it;

        QPointF vectorToTarget = point - particle->pos();

        particle->setPos(particle->pos() + vectorToTarget/50);
    }
}
