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
#ifndef PLAYER_H
#define PLAYER_H

#include <ctime> // clock_t

#include <Eigen/Geometry>

#include "Controller.hpp"
#include "GameObject.hpp"

class Player : public GameObject
{
   public:
   Player(Eigen::Vector2d position, Controller *controller);
   ~Player();
   void Update(GameState *gameState);

   void TurnLeft();
   void TurnRight();
   void Thrust();
   void Fire();

   private:
   Player();
   Player(const Player &player);
   Player & operator=(const Player &player);

   double acceleration;                // acceleration (in pixels/s^2)
   double damping;                     // damping coefficent - decreases velocity over time
   double vBullet;                     // velocity for fired bullets (in pixels/second)
   clock_t fireRefresh;                // how long to wait between firing bullets (in clock units) // TODO change to ms
   clock_t lastFireTime;               // last time a bullet was fired
   clock_t bulletLifetime;             // how long bullets should persisit before disappearing (in clock units) // TODO change to ms
   Eigen::Vector2d forward;            // vector indicating the default forward direction
   Eigen::Rotation2D<double> vRot;     // rotation matrix describing rotation speed 
   Eigen::Rotation2D<double> rotation; // rotation matrix describing current rotation
   std::vector<Eigen::Vector2d> defaultPolygon;
   Controller *controller;             // controls player movement

};

#endif // PLAYER_H
