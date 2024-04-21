#ifndef PARTICLEFACTORYMETHOD_H
#define PARTICLEFACTORYMETHOD_H

#include "particle.h"

class ParticleFactoryMethod
{
public:
    ParticleFactoryMethod();
    Particle* createParticle(int x, int y, QString name);
};

#endif // PARTICLEFACTORYMETHOD_H
