#ifndef PARTICLEWORKER_H
#define PARTICLEWORKER_H

#include "particle.h"
#include <QObject>

class ParticleWorker : public QObject
{
    Q_OBJECT
public:
    explicit ParticleWorker(QObject *parent = nullptr);
    void animate(QList<Particle *> &firstGroup, QList<Particle *> &secondGroup, double g, int radius);
signals:
};

#endif // PARTICLEWORKER_H
