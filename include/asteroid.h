#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>

#include <Eigen/Geometry>

#include "gameObject.h"

class Asteroid : public GameObject
{
    public:
    Asteroid(Eigen::Vector2d position, Eigen::Vector2d velocity, int radius);
    ~Asteroid();
};

#endif // ASTEROID_H
