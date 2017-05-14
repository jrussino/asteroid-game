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

    protected:
    Eigen::Vector2d direction;
    double vRot;
    double acceleration;
    double drag;

    private:
    Eigen::Rotation2D<double> rotationMatrix;
};

#endif // PLAYER_H
