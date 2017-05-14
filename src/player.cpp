#include "player.h"

#include <Eigen/Geometry>

Player::Player(Eigen::Vector2d position) :
    GameObject(position),
    direction(0.0,-1.0),
    acceleration(0.2),
    drag(0.995),
    rotationMatrix(0.1)
{
}

Player::~Player()
{
}

void Player::Update(int screenWidth, int screenHeight)
{
    GameObject::Update(screenWidth, screenHeight);
    velocity *= drag;
}

void Player::TurnLeft()
{
    direction = rotationMatrix.inverse()*direction;
}

void Player::TurnRight()
{
    direction = rotationMatrix*direction;
}

void Player::Thrust()
{
    velocity += direction * acceleration;
}

void Player::Fire()
{
    printf("\tFire\n");
}
