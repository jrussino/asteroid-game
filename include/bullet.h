#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include <Eigen/Geometry>

#include "gameObject.h"

class Bullet : public GameObject
{
    public:
    Bullet(Eigen::Vector2d position, Eigen::Vector2d velocity);
    ~Bullet();
//    std::pair<short int*, short int*> GetPolygon();
};

#endif // BULLET_H
