//------------------------------------------------------------------------------
//                                  Asteroid 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
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

class Asteroid : public GameObject
{
   public:
   Asteroid(const Eigen::Vector2d &position,
            const Eigen::Vector2d &velocity);
   ~Asteroid();

   private:
   Asteroid(const Asteroid &asteroid);
   Asteroid & operator=(const Asteroid &asteroid);
   Asteroid();

};

#endif // Asteroid_hpp
