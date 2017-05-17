//------------------------------------------------------------------------------
//                                 Game 
//------------------------------------------------------------------------------
// This file is part of asteroid-game
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Handles game execution.
 */
//------------------------------------------------------------------------------
#include <ctime>    // clock_t, clock()
#include <iostream> // cerr
#include <queue>    // queue
#include <vector>   // vector

#include "Collisions.hpp"
#include "Game.hpp"

namespace asteroid_game {

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// Game(GameState &gameState)
//------------------------------------------------------------------------------
/**
 * Constructs a new game.
 *
 * @param <gameState> contains game configuration and state information
 */
//------------------------------------------------------------------------------
Game::Game(GameState &gameState) :
   state(gameState),
   renderer(gameState.GetScreenWidth(), gameState.GetScreenHeight())
{
}

//------------------------------------------------------------------------------
// ~Game()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
Game::~Game()
{
   renderer.Clear();

   for (std::vector<GameObject*>::iterator gameObject = gameObjects.begin();
      gameObject != gameObjects.end();
      ++gameObject)
   {
     delete *gameObject;
   }
}

//------------------------------------------------------------------------------
// void AddObject(GameObject *gameObject)
//------------------------------------------------------------------------------
/**
 * Adds objects to the game.
 *
 * @param <gameObject> pointer to the object to add
 */
//------------------------------------------------------------------------------
void Game::AddObject(GameObject *gameObject)
{
   gameObjects.push_back(gameObject);
}

//------------------------------------------------------------------------------
// void Run()
//------------------------------------------------------------------------------
/**
 * Runs the game until completion.
 */
//------------------------------------------------------------------------------
void Game::Run()
{
   // Initialize the renderer
   if (renderer.Initialize() == false)
   {
      std::cerr << "ERROR - could not initialize renderer; game will not proceed."
                << std::endl;
      return;
   }

   // Run until no more lives left
   std::queue<GameObject*> toAddQueue;
   std::queue<GameObject*> toRemoveQueue;
   while ( (state.nLives > 0) && (state.isActive == true) )
   {
      clock_t loopStart = clock();

      // Check for collisions
      for (int i = 0; i < gameObjects.size()-1; ++i)
      {
         for (int j = i+1; j < gameObjects.size(); ++j)
         {
            if (collisions::CheckCollision(gameObjects[i],
                                           gameObjects[j]) == true)
            {
               std::cout << clock() << "\tCOLLISION!" << std::endl;
               gameObjects[i]->OnCollisionWith(gameObjects[j]->GetColliderType());
               gameObjects[j]->OnCollisionWith(gameObjects[i]->GetColliderType());
            }
         }
      }

      //Update positions of all game objects and redraw
      std::vector<GameObject*> newObjects;
      renderer.Clear();
      for (std::vector<GameObject*>::iterator gameObject = gameObjects.begin();
           gameObject != gameObjects.end();
           ++gameObject)
      {
         (*gameObject)->Update(&state);
         std::vector<GameObject*> newObjects = (*gameObject)->GetNewObjects();
         for (std::vector<GameObject*>::iterator newObject = newObjects.begin();
            newObject != newObjects.end(); ++newObject)
         {
            toAddQueue.push(*newObject);
         }
         if ((*gameObject)->IsActive() == false)
         {
            toRemoveQueue.push(*gameObject);
         }
         else
         {
            renderer.DrawObject(*gameObject);
         }
      }
      
      renderer.Render();

      // Remove inactive objects
      while (toRemoveQueue.size() > 0)
      {
         auto it = std::find(gameObjects.begin(), 
                             gameObjects.end(), 
                             toRemoveQueue.front()); 
         if (it != gameObjects.end())
         {
            gameObjects.erase(it); 
         }
         toRemoveQueue.pop();
      }
      // Add new objects
      while (toAddQueue.size() > 0)
      {
         gameObjects.push_back(toAddQueue.front());
         toAddQueue.pop();
      }

      clock_t  elapsedTime = clock() - loopStart;
      float elapsedTime_ms = (clock() - loopStart) * (1000.0/CLOCKS_PER_SEC);
      if (elapsedTime_ms < 1000.0/state.GetFPS())
      {
         SDL_Delay(static_cast<int>(1000.0/state.GetFPS() - elapsedTime_ms));
      }
   } 
}

} // namespace asteroid_game
