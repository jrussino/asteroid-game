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
 * @param <position>   initial position vector
 * @param <controller> object that can alter player state (e.g. based on
 * keyboard/joystick inputs, or some algorithm)
 *
 * TODO make other member vars configurable
 */
//------------------------------------------------------------------------------
Player::Player(const Eigen::Vector2d &position, Controller *const controller) :
   GameObject(position, GameObject::ColliderType::PLAYER),
   controller(controller),
   startPos(position),
   acceleration(0.2),
   damping(0.995),
   forward(0.0,-1.0),
   bulletLifetime(18000),
   fireRefresh(5000),
   vBullet(10.0),
   vRot(0.1),
   rotation(0.0)
{
   // Player ship is an arrowhead
   std::vector<Eigen::Vector2d> vertices;
   vertices.push_back(Eigen::Vector2d(0.0, -10.0));
   vertices.push_back(Eigen::Vector2d(-5.0, 5.0));
   vertices.push_back(Eigen::Vector2d(0.0, 4.0));
   vertices.push_back(Eigen::Vector2d(5.0, 5.0));
   SetPolygon(vertices);
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
   velocity *= damping;
   std::vector<Controller::Command> commands = controller->Update();
   for (std::vector<Controller::Command>::iterator command = commands.begin();
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
         isActive = false;
         newGameObjects.push_back(new Player(startPos, controller));
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
      polygon[i].start = rotation * defaultPolygon[i].start;
      polygon[i].end = rotation * defaultPolygon[i].end;
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
      polygon[i].start = rotation * defaultPolygon[i].start;
      polygon[i].end = rotation * defaultPolygon[i].end;
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
