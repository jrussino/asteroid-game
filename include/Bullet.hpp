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
