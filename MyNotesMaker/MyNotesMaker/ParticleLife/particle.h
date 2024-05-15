#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsEllipseItem>
#include <QSet>

/*!
 * \struct ParticleData
 * \brief Structure representing particle data such as color and radius.
 */
struct ParticleData {
    QString color; //!< Color of the particle.
    double radius; //!< Radius of the particle.
    ParticleData() : color(""), radius(0) {}
    ParticleData(QString color, double radius) : color(color), radius(radius) {}
};

/*!
 * \class Particle
 * \brief Represents a particle in a graphics scene.
 */
class Particle : public QGraphicsEllipseItem
{
private:
    double vx; //!< Velocity along the x-axis.
    double vy; //!< Velocity along the y-axis.
    const ParticleData* data; //!< Pointer to the ParticleData associated with the particle.

public:
    /*!
     * \brief Constructor for the Particle class.
     * \param xspread The spread of x coordinates.
     * \param yspread The spread of y coordinates.
     * \param radius The radius of the particle.
     * \param color The color of the particle.
     * \param data Pointer to the ParticleData associated with the particle.
     */
    Particle(int xspread, int yspread, const ParticleData* data);

    /*!
     * \brief Gets the velocity along the x-axis.
     * \return The velocity along the x-axis.
     */
    double getVX();

    /*!
     * \brief Gets the velocity along the y-axis.
     * \return The velocity along the y-axis.
     */
    double getVY();

    /*!
     * \brief Sets the velocity along the x-axis.
     * \param tx The velocity along the x-axis to set.
     */
    void setVX(double tx);

    /*!
     * \brief Sets the velocity along the y-axis.
     * \param ty The velocity along the y-axis to set.
     */
    void setVY(double ty);

    /*!
     * \brief Gets the color of the particle.
     * \return The color of the particle.
     */
    QString getColor();

    /*!
     * \brief Gets the radius of the particle.
     * \return The radius of the particle.
     */
    double getRadius();
};

#endif // PARTICLE_H
