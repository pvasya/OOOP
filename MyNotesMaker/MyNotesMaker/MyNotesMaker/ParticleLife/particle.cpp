#include "particle.h"
#include "qbrush.h"

Particle::Particle(int xspread, int yspread, int radius, QColor color):QGraphicsEllipseItem(0)
{
    vx = 0;
    vy = 0;
    setBrush(color);
    setRect(0, 0, radius, radius);
    setPos(xspread,yspread);
}
