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
   bool active;                             // whether or not this game object is active
   GameState *gameState;                    // pointer to curent game state
   Eigen::Vector2d velocity;                // velocity (in pixels/second)
   std::vector<Eigen::Vector2d> polygon;    // polygon describing shape of the object
   std::vector<GameObject*> newGameObjects; // container for new objects instantiated by this one

   private:
   GameObject();
   GameObject(const GameObject &gameObject);
   GameObject & operator=(const GameObject &gameObject);

   Eigen::Vector2d position; // position on screen (in pixels)
};

#endif // GAMEOBJECT_H
