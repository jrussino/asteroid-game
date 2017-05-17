//------------------------------------------------------------------------------
//                                 GameObject 
//------------------------------------------------------------------------------
// This file is part of asteroid-game
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
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

namespace asteroid_game {

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// GameObject(const Eigen::Vector2d &position)
//------------------------------------------------------------------------------
/**
 * Constructs Game Object with starting position.
 *
 * @param <position> initial position vector
 */
//------------------------------------------------------------------------------
GameObject::GameObject(const Eigen::Vector2d &position) :
   position(position),
   velocity(0,0),
   active(true),
   boundingCircleRadius(-1) // set to a negative value to signal uninitialized
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
// void Update(GameState * const gameState)
//------------------------------------------------------------------------------
/**
 * Updates Game Object based on the current game state.
 *
 * @param <gameState> pointer to state of the game
 */
//------------------------------------------------------------------------------
void GameObject::Update(GameState * const gameState)
{
   newGameObjects.clear();

   position(0) = wrapValue(position(0) + velocity(0),
                     0, 
                     gameState->GetScreenWidth());
   position(1) = wrapValue(position(1) + velocity(1),
                     0,
                     gameState->GetScreenHeight());
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

//------------------------------------------------------------------------------
// double GetBoundingCircleRadius()
//------------------------------------------------------------------------------
/**
 * Returns the radius of the bounding circle for this object's polygon
 *
 * @return double boundingCircleRadius
 */
//------------------------------------------------------------------------------
double GameObject::GetBoundingCircleRadius()
{
   // Calculate once and store
   if (boundingCircleRadius < 0)
   {
      // Finds max-length vector in the polygon (since its points are
      // represented as a set of Eigen::Vector2d centered around the origin)
      auto maxVector = std::max_element(polygon.begin(), 
                                        polygon.end(), 
                                        [](Eigen::Vector2d lhs, Eigen::Vector2d rhs){return rhs.norm() > lhs.norm();});
      boundingCircleRadius = (*maxVector).norm();
   }
   return boundingCircleRadius;
}

//-------------------------------
// global methods
//-------------------------------

double wrapValue(double value, double minVal, double maxVal)
{
   double range = maxVal - minVal;
   double tmpVal = value + range;
   return fmod(tmpVal, range);
}

} // namespace asteroid_game
