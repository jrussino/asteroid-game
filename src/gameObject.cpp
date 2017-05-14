#include "gameObject.h"

#include <math.h>
#include <Eigen/Geometry>


double wrapValue(double value, double minVal, double maxVal)
{
    double range = maxVal - minVal;
    double tmpVal = value + range;
    return fmod(tmpVal, range);
}

GameObject::GameObject(Eigen::Vector2d position) :
    position(position),
    velocity(0,0)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(int screenWidth, int screenHeight)
{
    position(0) = wrapValue(position(0) + velocity(0), 0, screenWidth);
    position(1) = wrapValue(position(1) + velocity(1), 0, screenHeight);
}

Eigen::Vector2i GameObject::GetPos()
{
    return position.cast<int>();
}
