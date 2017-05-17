//------------------------------------------------------------------------------
//                                 Player 
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
 * Player-type game object
 */
//------------------------------------------------------------------------------
#ifndef Player_hpp
#define Player_hpp

#include <ctime> // clock_t

#include <Eigen/Geometry>

#include "Controller.hpp"
#include "GameObject.hpp"
#include "GameState.hpp"

namespace asteroid_game {

class Player : public GameObject
{
   public:
   Player(const Eigen::Vector2d &position, Controller *const controller);
   ~Player();
   void Update(GameState *const gameState);
   void OnCollisionWith(GameObject::ColliderType colliderType,
                        GameState *const gameState);

   void TurnLeft();
   void TurnRight();
   void Thrust();
   void Fire();

   private:
   Player();
   Player(const Player &player);
   Player & operator=(const Player &player);

   Controller *controller;               // controls player movement
   const double acceleration;            // acceleration (in pixels/s^2)
   const double damping;                 // damping coefficent - decreases velocity over time
   const Eigen::Vector2d forward;        // vector indicating the default forward direction
   const clock_t bulletLifetime;         // how long bullets should persisit before disappearing (in clock units) // TODO change to ms
   const clock_t fireRefresh;            // how long to wait between firing bullets (in clock units) // TODO change to ms
   const double vBullet;                 // velocity for fired bullets (in pixels/second)
   const Eigen::Rotation2D<double> vRot; // rotation matrix describing rotation speed 

   clock_t lastFireTime;                // last time a bullet was fired
   Eigen::Rotation2D<double> rotation;  // rotation matrix describing current rotation
   std::vector<Eigen::Vector2d> defaultPolygon;

};

} // namespace asteroid_game

#endif // Player_hpp
