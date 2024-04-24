#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsEllipseItem>

class Particle : public QGraphicsEllipseItem
{
private:
    double vx, vy;
public:
    Particle(int xspread, int yspread, int radius, QColor color);

    double getVX();
    double getVY();
    void setVX(double tx);
    void setVY(double ty);
};

#endif // PARTICLE_H
