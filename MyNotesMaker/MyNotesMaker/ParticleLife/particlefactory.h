#ifndef PARTICLEFACTORY_H
#define PARTICLEFACTORY_H

#include <QMap>
#include "particle.h"

class ParticleFactory
{
private:
    QMap<QString, ParticleData*> dataMap;

public:
    ParticleFactory();
    ~ParticleFactory();

    Particle* createParticle(int x, int y, QString name);
};

#endif // PARTICLEFACTORY_H
