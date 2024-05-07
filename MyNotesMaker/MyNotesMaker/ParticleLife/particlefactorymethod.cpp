#include "particlefactorymethod.h"

ParticleFactoryMethod::ParticleFactoryMethod() {}

Particle *ParticleFactoryMethod::createParticle(int x, int y, QString name)
{
    ParticleData data;
    if(name == "redSmall"){
        data.color = "red";
        data.radius = 7;
        auto b = dataSet.indexOf(data);
        if(b == -1){
            dataSet.append(data);
        }
        b = dataSet.indexOf(data);
        return new Particle(x, y, data.radius,QColor(255, 0, 0, 255), &(dataSet.at(b)));
    }
    if(name == "greenSmall"){
        data.color = "green";
        data.radius = 7;
        auto b = dataSet.indexOf(data);
        if(b == -1){
            dataSet.append(data);
        }
        b = dataSet.indexOf(data);
        return new Particle(x, y, data.radius,QColor(0, 255, 0, 255), &(dataSet.at(b)));
    }
    if(name == "blueSmall"){
        data.color = "blue";
        data.radius = 7;
        auto b = dataSet.indexOf(data);
        if(b == -1){
            dataSet.append(data);
        }
        b = dataSet.indexOf(data);
        return new Particle(x, y, data.radius,QColor(0, 0, 255, 255), &(dataSet.at(b)));
    }
    if(name == "redBig"){
        data.color = "red";
        data.radius = 30;
        auto b = dataSet.indexOf(data);
        if(b == -1){
            dataSet.append(data);
        }
        b = dataSet.indexOf(data);
        return new Particle(x, y, data.radius,QColor(255, 0, 0, 255), &(dataSet.at(b)));
    }
    if(name == "greenBig"){
        data.color = "green";
        data.radius = 30;
        auto b = dataSet.indexOf(data);
        if(b == -1){
            dataSet.append(data);
        }
        b = dataSet.indexOf(data);
        return new Particle(x, y, data.radius,QColor(0, 255, 0, 255), &(dataSet.at(b)));
    }
    if(name == "blueBig"){
        data.color = "blue";
        data.radius = 30;
        auto b = dataSet.indexOf(data);
        if(b == -1){
            dataSet.append(data);
        }
        b = dataSet.indexOf(data);
        return new Particle(x, y, data.radius,QColor(0, 0, 255, 255), &(dataSet.at(b)));
    }
    data.color = "red";
    data.radius = 7;
    auto b = dataSet.indexOf(data);
    return new Particle(x, y, data.radius,QColor(0, 0, 255, 255), &(dataSet.at(b)));
}
