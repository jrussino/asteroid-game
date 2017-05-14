#include "bullet.h"

#include <Eigen/Geometry>

Bullet::Bullet(Eigen::Vector2d position, Eigen::Vector2d velocity) :
    GameObject(position)
{
    this->velocity = velocity;

    // Bullet is a small octagon
    double radius = 2;
    int nVertices = 8;
    polygon.clear();
    for(int i = 0; i < nVertices; ++i)
    {
        double x = radius*sin(i*2*M_PI/nVertices);
        double y = radius*cos(i*2*M_PI/nVertices);
        polygon.push_back(Eigen::Vector2d(x, y));
    }
}

Bullet::~Bullet()
{
}
