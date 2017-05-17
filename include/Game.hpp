//------------------------------------------------------------------------------
//                                 Game 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Handles game execution.
 */
//------------------------------------------------------------------------------
#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "GameObject.hpp"
#include "GameState.hpp"
#include "Renderer.hpp"

class Game
{
   public:
   Game(GameState &gameState);
   ~Game();
   
   void AddObject(GameObject *gameObject);
   void Run();

   private:
   Game();
   Game(const Game &game);
   Game & operator=(const Game &game);

   GameState &state;
   Renderer renderer;
   std::vector<GameObject*> gameObjects;
   
};

#endif // Game_hpp
