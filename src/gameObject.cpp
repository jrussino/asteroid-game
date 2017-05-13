#include "gameObject.h"

#include <math.h>


double wrapValue(double value, double minVal, double maxVal)
{
    double range = maxVal - minVal;
    double tmpVal = value + range;
    return fmod(tmpVal, range);
}

GameObject::GameObject(std::vector<double> position, std::vector<double> velocity) :
    position(position),
    velocity(velocity)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(int screenWidth, int screenHeight)
{
    position[0] = wrapValue(position[0] + velocity[0], 0, screenWidth);
    position[1] = wrapValue(position[1] + velocity[1], 0, screenHeight);
}

std::vector<int> GameObject::GetPos()
{
    return {(int)position[0], (int)position[1]}; 
}
