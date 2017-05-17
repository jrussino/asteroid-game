//------------------------------------------------------------------------------
//                                 Collisions
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
 * Namespace containing functions related to collision detection
 */
//------------------------------------------------------------------------------
#ifndef Collisions_hpp
#define Collisions_hpp

#include "GameObject.hpp"

namespace asteroid_game {
namespace collisions {

bool CheckCollision(GameObject *const gameObjectA,
                    GameObject *const gameObjectB);

} // namespace collisions
} // namespace asteroid_game

#endif // Collisions_hpp
