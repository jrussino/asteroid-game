#include "asteroid.hpp"

#include <Eigen/Geometry>

Asteroid::Asteroid(Eigen::Vector2d position, Eigen::Vector2d velocity, int radius) :
    GameObject(position)
{
    this->velocity = velocity;
}

Asteroid::~Asteroid()
{
}
