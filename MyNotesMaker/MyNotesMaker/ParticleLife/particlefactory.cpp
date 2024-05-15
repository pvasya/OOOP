#include "particlefactory.h"

ParticleFactory::ParticleFactory() {
    dataMap["redSmall"] = new ParticleData("red", 7);
    dataMap["greenSmall"] = new ParticleData("green", 7);
    dataMap["blueSmall"] = new ParticleData("blue", 7);
    dataMap["redBig"] = new ParticleData("red", 30);
    dataMap["greenBig"] = new ParticleData("green", 30);
    dataMap["blueBig"] = new ParticleData("blue", 30);
}

ParticleFactory::~ParticleFactory()
{
    for (auto it = dataMap.begin(); it != dataMap.end(); ++it) {
        delete it.value();
    }
    dataMap.clear();
}
// dataSet["redSmall"] = {"red", 7};

//ParticleData* data = dataMap[name];
//return new Particle(x, y, data->radius, data->getColor(), data);
Particle *ParticleFactory::createParticle(int x, int y, QString name)
{
    return new Particle(x, y, dataMap[name]);
}
