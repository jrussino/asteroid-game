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
#include "Game.hpp"

#include <queue>
#include <time.h>


//------------------------------------------------------------------------------
// Game(GameState gameState)
//------------------------------------------------------------------------------
/**
 * Constructs a new game.
 *
 * @param <gameState> contains game configuration and state information
 */
//------------------------------------------------------------------------------
Game::Game(GameState gameState) :
   state(gameState),
   renderer(gameState.screenWidth, gameState.screenHeight)
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
   // Run until no more lives left
   std::queue<GameObject*> toAddQueue;
   std::queue<GameObject*> toRemoveQueue;
   while ( (state.nLives > 0) && (state.active == true) )
   {
     clock_t loopStart = clock();

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
     if (elapsedTime_ms < 1000.0/state.fps)
     {
       SDL_Delay(static_cast<int>(1000.0/state.fps - elapsedTime_ms));
     }
   } 
}
