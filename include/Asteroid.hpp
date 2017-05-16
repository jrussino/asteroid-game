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
#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>

#include <Eigen/Geometry>

#include "GameObject.hpp"

class Asteroid : public GameObject
{
   public:
   Asteroid(Eigen::Vector2d position, Eigen::Vector2d velocity, int radius);
   ~Asteroid();
};

#endif // ASTEROID_H
