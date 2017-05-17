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
#ifndef Gameobject_hpp
#define Gameobject_hpp

#include <vector> // vector

#include <Eigen/Geometry>

#include "GameState.hpp"

namespace asteroid_game {

class GameObject
{
   public:
   GameObject(const Eigen::Vector2d &position);
   //---------------------------------------------------------------------------
   // virtual ~GameObject()
   //---------------------------------------------------------------------------
   /**
   * Pure virtual destructor - GameObject class cannot be instantiated; derived
   * classes must implement
   */
   //---------------------------------------------------------------------------
   virtual ~GameObject() = 0;

   virtual void Update(GameState * const gameState);
   std::vector<GameObject*> GetNewObjects();
   Eigen::Vector2d GetPosition();
   std::pair<std::vector<short int>, std::vector<short int> > GetPolygon();
   bool IsActive();
   double GetBoundingCircleRadius();

   protected:
   bool active;                             // whether or not this game object is active
   GameState *gameState;                    // pointer to curent game state
   Eigen::Vector2d velocity;                // velocity (in pixels/second)
   std::vector<Eigen::Vector2d> polygon;    // polygon describing shape of the object
   std::vector<GameObject*> newGameObjects; // container for new objects instantiated by this one

   private:
   GameObject();
   GameObject(const GameObject &gameObject);
   GameObject & operator=(const GameObject &gameObject);

   Eigen::Vector2d position;    // position on screen (in pixels)
   double boundingCircleRadius; // radius of the bounding circle for the object's polygon
};

//-------------------------------
// global declarations
//-------------------------------

double wrapValue(double value, double minVal, double maxVal);

} // namespace asteroid_game

#endif // Gameobject_hpp
