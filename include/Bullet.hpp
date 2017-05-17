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
#ifndef Bullet_hpp
#define Bullet_hpp

#include <ctime> // clock_t

#include <Eigen/Geometry>

#include "GameObject.hpp"

class Bullet : public GameObject
{
   public:
   Bullet(const Eigen::Vector2d &position, 
          const Eigen::Vector2d &velocity, 
          clock_t lifetime);
   ~Bullet();

   void Update(GameState *const gameState);

   private:
   Bullet();
   Bullet(const Bullet &bullet);
   Bullet & operator=(Bullet &bullet);

   const clock_t lifetime;  // lifetime duration in clock units
   clock_t startTime; // start time in clock units
};

#endif // Bullet_hpp
