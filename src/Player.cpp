#include "Player.hpp"

#include <Eigen/Geometry>

#include "Bullet.hpp"

Player::Player(Eigen::Vector2d position, Controller *controller) :
    GameObject(position),
    controller(controller),
    forward(0.0,-1.0),
    acceleration(0.2),
    drag(0.995),
    vRot(0.1),
    vBullet(10.0),
    fireRefresh(5000),
    bulletLifetime(18000),
    rotation(0.0)
{
    // Player ship is an arrowhead
    polygon.clear();
    polygon.push_back(Eigen::Vector2d(0.0, -10.0));
    polygon.push_back(Eigen::Vector2d(-5.0, 5.0));
    polygon.push_back(Eigen::Vector2d(0.0, 4.0));
    polygon.push_back(Eigen::Vector2d(5.0, 5.0));
    defaultPolygon = polygon;

    lastFireTime = clock();
}

Player::~Player()
{
}

void Player::Update(GameState *gameState)
{
    GameObject::Update(gameState);
    velocity *= drag;
    std::vector<Controller::Command> commands = controller->Update();
    for(std::vector<Controller::Command>::iterator command = commands.begin(); command != commands.end(); ++command)
    {
        switch( *command )
        {
            case Controller::Command::TURN_LEFT :
            TurnLeft();
            break;

            case Controller::Command::TURN_RIGHT :
            TurnRight();
            break;

            case Controller::Command::THRUST :
            Thrust();
            break;

            case Controller::Command::FIRE :
            Fire();
            break;

            case Controller::Command::QUIT :
            gameState->active = false;
            break;
        }
    }
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
    clock_t now = clock();
    if(now - lastFireTime > fireRefresh)
    {
        newGameObjects.push_back(new Bullet(GetPosition(), velocity + vBullet * (rotation * forward), bulletLifetime));
        lastFireTime = now;
    }
}
