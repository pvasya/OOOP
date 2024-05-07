#include "particle.h"
#include "qbrush.h"

Particle::Particle(int xspread, int yspread, int radius, QColor color, const ParticleData *data):QGraphicsEllipseItem(0)
{   
    this->data = data;
    this->vx = 0;
    this->vy = 0;
    setBrush(color);
    setRect(0, 0, radius, radius);
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

void Particle::setVX(double tx)
{
    this->vx = tx;
}

void Particle::setVY(double ty)
{
    this->vy = ty;
}

QString Particle::getColor()
{
    return data->color;
}

double Particle::getRadius()
{
    return data->radius;
}

