#ifndef MOVETOMOUSEWORKER_H
#define MOVETOMOUSEWORKER_H

#include "particle.h"
#include <QObject>

class MoveToMouseWorker : public QObject
{
    Q_OBJECT
public:
    explicit MoveToMouseWorker(QObject *parent = nullptr);

private:
    void moveParticlesToTarget(QList<Particle*>& particles, QPointF point);

public:
    void animateToMouse(QPointF point, QList<Particle*>& redParticles,
                                       QList<Particle*>& greenParticles,
                                       QList<Particle*>& blueParticles);

signals:
};

#endif // MOVETOMOUSEWORKER_H
