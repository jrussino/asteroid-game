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
#ifndef BULLET_H
#define BULLET_H

#include <time.h>
#include <vector>

#include <Eigen/Geometry>

#include "GameObject.hpp"

class Bullet : public GameObject
{
   public:
   Bullet(Eigen::Vector2d position,
         Eigen::Vector2d velocity, 
         clock_t lifetime);
   ~Bullet();
   void Update(GameState *gameState);

   private:
   clock_t lifetime;  // lifetime duration in clock units
   clock_t startTime; // start time in clock units
};

#endif // BULLET_H
