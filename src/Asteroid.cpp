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

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// Asteroid(const Eigen::Vector2d &position, const Eigen::Vector2d &velocity)
//------------------------------------------------------------------------------
/**
 * Constructs Asteroid objects with initial position and velocity.
 *
 * @param <position> initial position vector
 * @param <velocity> initial velocity vector
 */
//------------------------------------------------------------------------------
Asteroid::Asteroid(const Eigen::Vector2d &position, 
                   const Eigen::Vector2d &velocity) :
   GameObject(position)
{
   this->velocity = velocity;
}

//------------------------------------------------------------------------------
// ~Asteroid()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
Asteroid::~Asteroid()
{
}
