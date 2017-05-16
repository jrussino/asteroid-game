#ifndef BULLET_H
#define BULLET_H

#include <time.h>
#include <vector>

#include <Eigen/Geometry>

#include "GameObject.hpp"

class Bullet : public GameObject
{
    public:
    Bullet(Eigen::Vector2d position, Eigen::Vector2d velocity, clock_t lifetime);
    ~Bullet();
    void Update(GameState *gameState);

    private:
    clock_t lifetime;
    clock_t startTime;
};

#endif // BULLET_H
