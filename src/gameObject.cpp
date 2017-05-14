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
    velocity(0,0),
    active(true)
{
    // Default polygon = octagon of radius 10
    double radius = 10;
    int nVertices = 8;
    for(int i = 0; i < nVertices; ++i)
    {
        double x = radius*sin(i*2*M_PI/nVertices);
        double y = radius*cos(i*2*M_PI/nVertices);
        polygon.push_back(Eigen::Vector2d(x, y));
    }
}

GameObject::~GameObject()
{
}

void GameObject::Update(GameState* gameState)
{
    newGameObjects.clear();

    position(0) = wrapValue(position(0) + velocity(0), 0, gameState->screenWidth);
    position(1) = wrapValue(position(1) + velocity(1), 0, gameState->screenHeight);
}

Eigen::Vector2i GameObject::GetPos()
{
    return position.cast<int>();
}

std::pair<std::vector<short int>, std::vector<short int> > GameObject::GetPolygon()
{
    std::vector<short int> vertsX; 
    std::vector<short int> vertsY; 
    for(std::vector<Eigen::Vector2d>::iterator vertex = polygon.begin(); vertex != polygon.end(); ++vertex)
    {
        vertsX.push_back(static_cast<short int>((*vertex)(0) + position(0)));
        vertsY.push_back(static_cast<short int>((*vertex)(1) + position(1)));
    }

    return std::pair<std::vector<short int>, std::vector<short int> >(vertsX, vertsY);
}

Eigen::Vector2d GameObject::GetPosition()
{
    return position;
}

std::vector<GameObject*> GameObject::GetNewObjects()
{
    return newGameObjects;
}

bool GameObject::IsActive()
{
    return active;
}
