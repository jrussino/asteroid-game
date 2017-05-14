#include "player.h"

#include <Eigen/Geometry>

Player::Player(Eigen::Vector2d position) :
    GameObject(position),
    forward(0.0,-1.0),
    acceleration(0.2),
    drag(0.995),
    vRot(0.1),
    rotation(0.0)
{
    // Player ship is an arrowhead
    polygon.clear();
    polygon.push_back(Eigen::Vector2d(0.0, -10.0));
    polygon.push_back(Eigen::Vector2d(-5.0, 5.0));
    polygon.push_back(Eigen::Vector2d(0.0, 4.0));
    polygon.push_back(Eigen::Vector2d(5.0, 5.0));
    defaultPolygon = polygon;
}

Player::~Player()
{
}

void Player::Update(GameState* gameState)
{
    GameObject::Update(gameState);
    velocity *= drag;
}

void Player::TurnLeft()
{
    rotation = rotation * vRot.inverse();
    for(int i = 0; i < polygon.size(); ++i)
    {
        polygon[i] = rotation * defaultPolygon[i];
    }
}

void Player::TurnRight()
{
    rotation = rotation * vRot;
    for(int i = 0; i < polygon.size(); ++i)
    {
        polygon[i] = rotation * defaultPolygon[i];
    }
}

void Player::Thrust()
{
    velocity += acceleration * (rotation * forward);
}

void Player::Fire()
{
    printf("\tFire\n");
}
