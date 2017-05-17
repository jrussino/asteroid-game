//------------------------------------------------------------------------------
//                                 Player 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
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

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// Player(Eigen::Vector2d position, Controller *controller)
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
Player::Player(Eigen::Vector2d position, Controller *controller) :
   GameObject(position),
   controller(controller),
   forward(0.0,-1.0),
   acceleration(0.2),
   damping(0.995),
   vRot(0.1),
   vBullet(10.0),
   fireRefresh(5000),
   bulletLifetime(18000),
   rotation(0.0)
{
   // Player ship is an arrowhead
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
void Player::Update(GameState *gameState)
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
 *
 * @note bullet velocity will be (player velocity + (player direction * bullet 
 * speed))
 */
//------------------------------------------------------------------------------
void Player::Fire()
{
   clock_t now = clock();
   if (now - lastFireTime > fireRefresh)
   {
      newGameObjects.push_back(new Bullet(GetPosition(), 
                         velocity + vBullet * (rotation * forward),
                         bulletLifetime));
      lastFireTime = now;
   }
}
