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
#include "Asteroid.hpp"

#include <Eigen/Geometry>

Asteroid::Asteroid(Eigen::Vector2d position,
               Eigen::Vector2d velocity,
               int radius) :
   GameObject(position)
{
   this->velocity = velocity;
}

Asteroid::~Asteroid()
{
}
