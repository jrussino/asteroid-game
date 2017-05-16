//------------------------------------------------------------------------------
//                                 Bullet 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
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

//------------------------------------------------------------------------------
// Bullet(Eigen::Vector2d position, Eigen::Vector2d velocity, clock_t lifetime)
//------------------------------------------------------------------------------
/**
 * Constructs Bullet objects with initial position, velocity, and lifetime.
 *
 * @param <position> initial position vector
 * @param <velocity> initial velocity vector
 * @param <lifetime> time (s) the object will persist before disappearing
 */
//------------------------------------------------------------------------------
Bullet::Bullet(Eigen::Vector2d position, 
            Eigen::Vector2d velocity, 
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
void Bullet::Update(GameState *gameState)
{
   GameObject::Update(gameState);
   if (clock() - startTime > lifetime)
   {
      active = false;
   }
}
