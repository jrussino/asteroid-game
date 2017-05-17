//------------------------------------------------------------------------------
//                                 Bullet 
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
// Created: 2017/05/15
//
/**
 * Bullet-type game object
 */
//------------------------------------------------------------------------------
#include "Bullet.hpp"

#include <Eigen/Geometry>

namespace asteroid_game {

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// Bullet(const Eigen::Vector2d &position, 
//        const Eigen::Vector2d &velocity, 
//        clock_t lifetime)
//------------------------------------------------------------------------------
/**
 * Constructs Bullet objects with initial position, velocity, and lifetime.
 *
 * @param <position> initial position vector
 * @param <velocity> initial velocity vector
 * @param <lifetime> time (s) the object will persist before disappearing
 */
//------------------------------------------------------------------------------
Bullet::Bullet(const Eigen::Vector2d &position, 
               const Eigen::Vector2d &velocity, 
               clock_t lifetime) :
   GameObject(position),
   lifetime(lifetime)
{
   this->velocity = velocity;

   // Bullet is a small octagon
   double radius = 2;
   int nVertices = 8;
   polygon.clear();
   for (int i = 0; i < nVertices; ++i)
   {
      double x = radius*sin(i*2*M_PI/nVertices);
      double y = radius*cos(i*2*M_PI/nVertices);
      polygon.push_back(Eigen::Vector2d(x, y));
   }

   startTime = clock();
}

//------------------------------------------------------------------------------
// ~Bullet()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
Bullet::~Bullet()
{
}

//------------------------------------------------------------------------------
// void Update(GameState *gameState)
//------------------------------------------------------------------------------
/**
 * Updates bullet object based on the current game state.
 *
 * @param <gameState> pointer to state of the game
 */
//------------------------------------------------------------------------------
void Bullet::Update(GameState *const gameState)
{
   GameObject::Update(gameState);
   if (clock() - startTime > lifetime)
   {
      active = false;
   }
}

} // namespace asteroid_game
