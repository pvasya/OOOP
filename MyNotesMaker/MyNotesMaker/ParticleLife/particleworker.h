#ifndef PARTICLEWORKER_H
#define PARTICLEWORKER_H

#include "particle.h"
#include <QObject>

class ParticleWorker : public QObject
{
    Q_OBJECT

private:
    QList<Particle *>* firstGroup;
    QList<Particle *>* secondGroup;
    QList<Particle *>* thirdGroup;

public:
    explicit ParticleWorker(QObject *parent = nullptr);
    void animate(QList<Particle *> *firstGroup, QList<Particle *> *secondGroup, double g, int radius);
    void setLists(QList<Particle *> *p1, QList<Particle *> *p2, QList<Particle *> *p3);
public slots:
    void animation(double g1,double g2,double g3, int radius);
signals:
};

#endif // PARTICLEWORKER_H
