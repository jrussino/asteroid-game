//------------------------------------------------------------------------------
//                                  Asteroid 
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
 * Asteroid-type game object
 */
//------------------------------------------------------------------------------
#include "Asteroid.hpp"

#include <Eigen/Geometry>

namespace asteroid_game {

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// Asteroid(const Eigen::Vector2d &position, const Eigen::Vector2d &velocity)
//------------------------------------------------------------------------------
/**
 * Constructs Asteroid objects with initial position and velocity.
 *
 * @param <position> initial position vector
 * @param <velocity> initial velocity vector
 */
//------------------------------------------------------------------------------
Asteroid::Asteroid(const Eigen::Vector2d &position, 
                   const Eigen::Vector2d &velocity) :
   GameObject(position, GameObject::ColliderType::ASTEROID)
{
   this->velocity = velocity;
}

//------------------------------------------------------------------------------
// ~Asteroid()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
Asteroid::~Asteroid()
{
}

//------------------------------------------------------------------------------
// void OnCollisionWith(GameObject::ColliderType colliderType)
//------------------------------------------------------------------------------
/**
 * Specifies what to do when in collision with a particular type of object
 *
 * @param <colliderType> type of object we've collided with
 */
//------------------------------------------------------------------------------
void Asteroid::OnCollisionWith(GameObject::ColliderType colliderType)
{
   switch (colliderType)
   {
      case GameObject::ColliderType::ASTEROID:
         break;
      
      case GameObject::ColliderType::BULLET:
      case GameObject::ColliderType::PLAYER:
         isActive = false;
         break;

      default:
         break;
   }
}

} // asteroid_game
