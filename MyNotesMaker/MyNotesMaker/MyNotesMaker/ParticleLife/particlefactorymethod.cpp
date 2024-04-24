#include "particlefactorymethod.h"

ParticleFactoryMethod::ParticleFactoryMethod() {}

Particle *ParticleFactoryMethod::createParticle(int x, int y, QString name)
{
    if(name == "redSmall")
        return new Particle(x, y, 7,QColor(255, 0, 0, 255));
    if(name == "greenSmall")
        return new Particle(x, y, 7,QColor(0, 255, 0, 255));
    if(name == "blueSmall")
        return new Particle(x, y, 7,QColor(0, 0, 255, 255));
    if(name == "redBig")
        return new Particle(x, y, 30,QColor(255, 0, 0, 255));
    if(name == "greenBig")
        return new Particle(x, y, 30,QColor(0, 255, 0, 255));
    if(name == "blueBig")
        return new Particle(x, y, 30,QColor(0, 0, 255, 255));
    return new Particle(x, y, 10,QColor(255, 0, 0, 1));
}
