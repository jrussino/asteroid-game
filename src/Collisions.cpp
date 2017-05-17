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
#include "Collisions.hpp"

namespace asteroid_game {
namespace collisions {

//------------------------------------------------------------------------------
// bool CheckCollision(GameObject *const GameObjectA, 
//                     GameObject *const GameObjectB)
//------------------------------------------------------------------------------
/**
 * Checks whether two game objects' polygons are touching or overlapping
 *
 * @param <GameObjectA> first game object of the pair to test
 * @param <GameObjectB> second game object of the pair to test
 *
 * @return bool inCollision
 *
 * @note not yet fully implemented - only checks bounding-circle overlap, which
 * is meant to be a pruning step before actual collision detection
 */
//------------------------------------------------------------------------------
bool CheckCollision(GameObject *const GameObjectA, 
                    GameObject *const GameObjectB)
{
   // Check if object centers are closer than the sum of thier bounding circles'
   // radii; if not, they definitely don't overlap
   if ((GameObjectA->GetPosition() - GameObjectB->GetPosition()).norm()
       < (GameObjectA->GetBoundingCircleRadius()
         + GameObjectB->GetBoundingCircleRadius()))
   {
      //TODO The above is just a pruning step; do real collision checking here
      return true;
   }
   return false;
}

} // namespace collisions
} // namespace asteroid_game
