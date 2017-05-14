#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include <Eigen/Geometry>

#include "gameObject.h"

class Player : public GameObject
{
    public:
    Player(Eigen::Vector2d position);
    ~Player();
};

#endif // PLAYER_H
