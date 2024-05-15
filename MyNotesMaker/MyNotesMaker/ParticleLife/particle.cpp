#include "particle.h"
#include "qbrush.h"

Particle::Particle(int xspread, int yspread, const ParticleData *data):QGraphicsEllipseItem(0)
{   
    this->data = data;
    this->vx = 0;
    this->vy = 0;
    setBrush(QColor(this->data->color));
    setRect(0, 0, this->data->radius, this->data->radius);
    setPos(xspread,yspread);
}

double Particle::getVX()
{
    return this->vx;
}

double Particle::getVY()
{
    return this->vy;
}

void Particle::setVX(double tx){
    if(tx<5 && tx>-5)
        this->vx = tx;
    else this->vx = tx*0.5;
}

void Particle::setVY(double ty)
{
    if(ty<5 && ty>-5)
        this->vy = ty;
    else this->vy = ty*0.5;
}

QString Particle::getColor()
{
    return data->color;
}

double Particle::getRadius()
{
    return data->radius;
}

