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
#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <Eigen/Geometry>

#include "GameObject.hpp"

namespace asteroid_game {

class Asteroid : public GameObject
{
   public:
   Asteroid(const Eigen::Vector2d &position,
            const Eigen::Vector2d &velocity);
   ~Asteroid();

   void OnCollisionWith(GameObject::ColliderType colliderType);

   private:
   Asteroid(const Asteroid &asteroid);
   Asteroid & operator=(const Asteroid &asteroid);
   Asteroid();

};

} // namespace asteroid_game

#endif // Asteroid_hpp
