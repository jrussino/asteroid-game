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
#include <Eigen/Geometry>

#include "Player.hpp"
#include "Bullet.hpp"

namespace asteroid_game {

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// Player(const Eigen::Vector2d &position, Controller *const controller)
//------------------------------------------------------------------------------
/**
 * Constructs Player object with initial position and a controller.
 *
 * @param <position> initial position vector
 * @param <controller> object that can alter player state (e.g. based on
 * keyboard/joystick inputs, or some algorithm)
 * @param <double> acceleration in pixels/s^2
 * @param <double> damping coefficent - decreases velocity over time
 * @param <const Eigen::Vector2d &> forward indicates default forward direction
 * @param <clock_t> bulletLifetime how long bullets persist before disappearing
 * (in clock units)
 * @param <clock_t> fireRefresh how long to wait between firing bullets (in
 * clock units)
 * @param <double> vBullet velocity for fired bullets (in pixels/second)
 * @param <const Eigen::Rotation2D<double> &> vRot describes rotation speed
 * @param <const Eigen::Rotation2D<double> &> rotation current rotation
 *
 */
//------------------------------------------------------------------------------
Player::Player(const Eigen::Vector2d &position, 
               Controller *const controller,
               double acceleration,
               double damping,
               const Eigen::Vector2d &forward,
               clock_t bulletLifetime,
               clock_t fireRefresh,
               double vBullet,
               const Eigen::Rotation2D<double> &vRot,
               const Eigen::Rotation2D<double> &rotation) :
   GameObject(position, GameObject::ColliderType::PLAYER),
   controller(controller),
   startPos(position),
   acceleration(acceleration),
   damping(damping),
   forward(forward),
   bulletLifetime(bulletLifetime),
   fireRefresh(fireRefresh),
   vBullet(vBullet),
   vRot(vRot),
   rotation(rotation)
{
   // Player ship is an arrowhead
   // TODO this should be configurable
   polygon.clear();
   polygon.push_back(Eigen::Vector2d(0.0, -10.0));
   polygon.push_back(Eigen::Vector2d(-5.0, 5.0));
   polygon.push_back(Eigen::Vector2d(0.0, 4.0));
   polygon.push_back(Eigen::Vector2d(5.0, 5.0));
   defaultPolygon = polygon;

   lastFireTime = clock();
}

//------------------------------------------------------------------------------
// ~Player()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
Player::~Player()
{
}

//------------------------------------------------------------------------------
// void Update(GameState *gameState)
//------------------------------------------------------------------------------
/**
 * Updates player object based on the current game state and controller commands
 *
 * @param <gameState> pointer to state of the game
 */
//------------------------------------------------------------------------------
void Player::Update(GameState *const gameState)
{
   GameObject::Update(gameState);

   velocity *= damping; // slow down over time

   // Update based on controller commands
   std::vector<Controller::Command> commands = controller->Update();
   for (std::vector<Controller::Command>::const_iterator command = commands.begin();
       command != commands.end();
       ++command)
   {
      switch(*command)
      {
         case Controller::Command::TURN_LEFT :
            TurnLeft();
            break;

         case Controller::Command::TURN_RIGHT :
            TurnRight();
            break;

         case Controller::Command::THRUST :
            Thrust();
            break;

         case Controller::Command::FIRE :
            Fire();
            break;

         case Controller::Command::QUIT :
            gameState->isActive = false;
            break;

         default:
            // This should never happen
            printf("WARNING - Controller recieved an unknown command: %d",
                  *command);
            break;
      }
   }
}

//------------------------------------------------------------------------------
// void OnCollisionWith(GameObject::ColliderType colliderType,
//                      GameState *const gameState)
//------------------------------------------------------------------------------
/**
 * Specifies what to do when in collision with a particular type of object
 *
 * @param <colliderType> type of object we've collided with
 * @param <gameState> pointer to game state (in case we need to update it)
 */
//------------------------------------------------------------------------------
void Player::OnCollisionWith(GameObject::ColliderType colliderType,
                             GameState *const gameState)
{
   switch (colliderType)
   {
      case GameObject::ColliderType::ASTEROID:
         gameState->DecreaseLives(); // Colliding with asteroid removes a life
         // Player is destroyed, and a new one is placed back at its original 
         // starting position
         newGameObjects.push_back(new Player(startPos, controller)); 
         isActive = false;
         break;
      
      case GameObject::ColliderType::BULLET:
      case GameObject::ColliderType::PLAYER:
         break;

      default:
         break;
   }
}

//------------------------------------------------------------------------------
// void TurnLeft()
//------------------------------------------------------------------------------
/**
 * Rotates the player object counter-clockwise about its center.
 */
//------------------------------------------------------------------------------
void Player::TurnLeft()
{
   rotation = rotation * vRot.inverse();
   for (int i = 0; i < polygon.size(); ++i)
   {
      polygon[i] = rotation * defaultPolygon[i];
   }
}

//------------------------------------------------------------------------------
// void TurnRight()
//------------------------------------------------------------------------------
/**
 * Rotates the player object clockwise about its center.
 */
//------------------------------------------------------------------------------
void Player::TurnRight()
{
   rotation = rotation * vRot;
   for (int i = 0; i < polygon.size(); ++i)
   {
      polygon[i] = rotation * defaultPolygon[i];
   }
}

//------------------------------------------------------------------------------
// void Thrust()
//------------------------------------------------------------------------------
/**
 * Accelerates player object in the direction it is facing.
 */
//------------------------------------------------------------------------------
void Player::Thrust()
{
   velocity += acceleration * (rotation * forward);
}

//------------------------------------------------------------------------------
// void Fire()
//------------------------------------------------------------------------------
/**
 * Instantiates a new bullet object at player's location and adds it to the list
 * of game objects.
 */
//------------------------------------------------------------------------------
void Player::Fire()
{
   clock_t now = clock();
   if (now - lastFireTime > fireRefresh)
   {
      // Position bullet slightly in front of the player's polygon
      Eigen::Vector2d bulletPosition = GetPosition() 
                                       + (rotation * forward) 
                                         * (1.2 * GetBoundingCircleRadius());
      // Velocity is added to player's, in the forward-facing direction
      Eigen::Vector2d bulletVelocity = velocity + vBullet * (rotation* forward);
      newGameObjects.push_back(new Bullet(bulletPosition, 
                                          bulletVelocity,
                                          bulletLifetime));
      lastFireTime = now;
   }
}

} // namespace asteroid_game
