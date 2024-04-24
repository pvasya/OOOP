#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsEllipseItem>

class Particle : public QGraphicsEllipseItem
{
public:
    int vx, vy;
public:
    Particle(int xspread, int yspread, int radius, QColor color);
};

#endif // PARTICLE_H
