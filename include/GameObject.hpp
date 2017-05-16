//------------------------------------------------------------------------------
//                                 GameObject 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Base class for game objects
 */
//------------------------------------------------------------------------------
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include <Eigen/Geometry>

#include "GameState.hpp"

class GameObject
{
   public:
   GameObject(Eigen::Vector2d position);
   //---------------------------------------------------------------------------
   // virtual ~GameObject()
   //---------------------------------------------------------------------------
   /**
   * Pure virtual destructor - GameObject class cannot be instantiated; derived
   * classes must implement
   */
   //---------------------------------------------------------------------------
   virtual ~GameObject() = 0;

   virtual void Update(GameState *gameState);
   std::vector<GameObject*> GetNewObjects();
   Eigen::Vector2d GetPosition();
   std::pair<std::vector<short int>, std::vector<short int> > GetPolygon();
   bool IsActive();

   protected:
   bool active;
   GameState *gameState;
   Eigen::Vector2d velocity;
   std::vector<Eigen::Vector2d> polygon;
   std::vector<GameObject*> newGameObjects;

   private:
   Eigen::Vector2d position;
};

#endif // GAMEOBJECT_H
