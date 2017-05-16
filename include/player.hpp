#ifndef PLAYER_H
#define PLAYER_H

#include <time.h>
#include <vector>

#include <Eigen/Geometry>

#include "controller.hpp"
#include "gameObject.hpp"

class Player : public GameObject
{
    public:
    Player(Eigen::Vector2d position, Controller* controller);
    ~Player();
    void Update(GameState* gameState);

    void TurnLeft();
    void TurnRight();
    void Thrust();
    void Fire();

    private:
    double acceleration;
    double drag;
    double vBullet;
    clock_t fireRefresh;
    clock_t lastFireTime;
    clock_t bulletLifetime;
    Eigen::Vector2d forward;
    Eigen::Rotation2D<double>  vRot;
    Eigen::Rotation2D<double> rotation;
    std::vector<Eigen::Vector2d> defaultPolygon;
    Controller* controller;

};

#endif // PLAYER_H
