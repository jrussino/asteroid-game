//------------------------------------------------------------------------------
//                                 GameObject 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Base class for game objects
 */
//------------------------------------------------------------------------------
#include "GameObject.hpp"

#include <cmath> // sin, cos

#include <Eigen/Geometry>

double wrapValue(double value, double minVal, double maxVal)
{
   double range = maxVal - minVal;
   double tmpVal = value + range;
   return fmod(tmpVal, range);
}

//------------------------------------------------------------------------------
// GameObject(Eigen::Vector2d position)
//------------------------------------------------------------------------------
/**
 * Constructs Game Object with starting position.
 *
 * @param <position> initial position vector
 */
//------------------------------------------------------------------------------
GameObject::GameObject(Eigen::Vector2d position) :
   position(position),
   velocity(0,0),
   active(true)
{
   // Default polygon = octagon of radius 10
   double radius = 10;
   int nVertices = 8;
   for (int i = 0; i < nVertices; ++i)
   {
      double x = radius*sin(i*2*M_PI/nVertices);
      double y = radius*cos(i*2*M_PI/nVertices);
      polygon.push_back(Eigen::Vector2d(x, y));
   }
}

GameObject::~GameObject()
{
}

//------------------------------------------------------------------------------
// void Update(GameState *gameState)
//------------------------------------------------------------------------------
/**
 * Updates Game Object based on the current game state.
 *
 * @param <gameState> pointer to state of the game
 */
//------------------------------------------------------------------------------
void GameObject::Update(GameState *gameState)
{
   newGameObjects.clear();

   position(0) = wrapValue(position(0) + velocity(0),
                     0, 
                     gameState->screenWidth);
   position(1) = wrapValue(position(1) + velocity(1),
                     0,
                     gameState->screenHeight);
}

//------------------------------------------------------------------------------
// Eigen::Vector2d GetPosition()
//------------------------------------------------------------------------------
/**
 * Gets the current position of the Game Object.
 *
 * @return Eigen::Vector2d position
 */
//------------------------------------------------------------------------------
Eigen::Vector2d GameObject::GetPosition()
{
   return position;
}

//------------------------------------------------------------------------------
// std::pair<std::vector<short int>, std::vector<short int> > GetPolygon()
//------------------------------------------------------------------------------
/**
 * Gets the object polygon.
 *
 * @return std::pair<std::vector<short int>, std::vector<short int> > polygon
 */
//------------------------------------------------------------------------------
std::pair<std::vector<short int>, 
        std::vector<short int> > GameObject::GetPolygon()
{
   std::vector<short int> vertsX; 
   std::vector<short int> vertsY; 
   for (std::vector<Eigen::Vector2d>::iterator vertex = polygon.begin();
       vertex != polygon.end();
       ++vertex)
   {
      vertsX.push_back(static_cast<short int>((*vertex)(0) + position(0)));
      vertsY.push_back(static_cast<short int>((*vertex)(1) + position(1)));
   }

   return std::pair<std::vector<short int>,
                std::vector<short int> >(vertsX, vertsY);
}

//------------------------------------------------------------------------------
// std::vector<GameObject*> GetNewObjects()
//------------------------------------------------------------------------------
/**
 * Gets a list of new objects spawned by this object on the latest update step.
 *
 * @return std::vector<GameObject*> newObjects
 */
//------------------------------------------------------------------------------
std::vector<GameObject*> GameObject::GetNewObjects()
{
   return newGameObjects;
}

//------------------------------------------------------------------------------
// bool IsActive()
//------------------------------------------------------------------------------
/**
 * Whether or not this game object is marked as active.
 *
 * @return bool isActive
 */
//------------------------------------------------------------------------------
bool GameObject::IsActive()
{
   return active;
}
