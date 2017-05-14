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
    void Update(int screenWidth, int screenHeight);

    void TurnLeft();
    void TurnRight();
    void Thrust();
    void Fire();

    private:
    double acceleration;
    double drag;
    Eigen::Vector2d forward;
    Eigen::Rotation2D<double>  vRot;
    Eigen::Rotation2D<double> rotation;
    std::vector<Eigen::Vector2d> defaultPolygon;

};

#endif // PLAYER_H
