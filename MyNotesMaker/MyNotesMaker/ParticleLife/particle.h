#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsEllipseItem>
#include <QSet>

struct ParticleData{
    QString color;
    double radius;

    bool operator==(const ParticleData& other) const {
        return (color == other.color && radius == other.radius);
    }
};

class Particle : public QGraphicsEllipseItem
{
private:
    double vx, vy;
    const ParticleData* data;

public:
    Particle(int xspread, int yspread, int radius, QColor color, const ParticleData* data);
    double getVX();
    double getVY();
    void setVX(double tx);
    void setVY(double ty);
    QString getColor();
    double getRadius();
};

#endif // PARTICLE_H
