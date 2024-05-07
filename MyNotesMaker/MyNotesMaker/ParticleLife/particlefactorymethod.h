#ifndef PARTICLEFACTORYMETHOD_H
#define PARTICLEFACTORYMETHOD_H

#include <QList>
#include "particle.h"

class ParticleFactoryMethod
{
private:
    QList<ParticleData> dataSet;

public:
    ParticleFactoryMethod();

    Particle* createParticle(int x, int y, QString name);
};

#endif // PARTICLEFACTORYMETHOD_H
