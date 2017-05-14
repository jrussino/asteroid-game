#include "player.h"

#include <Eigen/Geometry>

Player::Player(Eigen::Vector2d position) :
    GameObject(position)
{
}

Player::~Player()
{
}
