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
// Created: 2017/05/12

#include <iostream> // cerr
#include <queue>    // queue
#include <random>   // uniform_real_distribution, default_random_engine

#include <Eigen/Geometry>

#include "Asteroid.hpp"
#include "Collisions.hpp"
#include "Controller.hpp"
#include "GameState.hpp"
#include "GameObject.hpp"
#include "KeyboardController.hpp"
#include "Player.hpp"
#include "Renderer.hpp"

using namespace asteroid_game;

// Configurable stuff:
unsigned int nAsteroids = 5;     // # of asteroids per round
unsigned int nLives = 3;         // number of player ships (aka how many times we can be hit before game ends)
unsigned int screenWidth = 640;  // width of game area (in pixels)
unsigned int screenHeight = 480; // height of game area (in pixels)
double vMax = 2.0;               // max asteroid speed (in pixels/second)
unsigned int fps = 60;           // frames to render per second


int main( int argc, char *argv[] )
{

   // Configure game
   GameState gameState(nLives, fps, screenWidth, screenHeight);
   std::vector<GameObject*> gameObjects;

   // Set up random value generators (for randomly-placed moving asteroids)
   std::uniform_real_distribution<double> randomX(0, screenWidth);
   std::uniform_real_distribution<double> randomY(0, screenHeight);
   std::uniform_real_distribution<double> randomV(-vMax, vMax);
   std::default_random_engine re;

   // Instantiate ship at center of screen
   KeyboardController *controller = new KeyboardController();
   Player *player = new Player(Eigen::Vector2d(screenWidth/2, screenHeight/2),
                        controller);
   gameObjects.push_back(player);

   // Initialize the renderer
   Renderer renderer(screenWidth, screenHeight);
   if (renderer.Initialize() == false)
   {
      std::cerr << "ERROR - could not initialize renderer; game will not proceed."
                << std::endl;
      return -1;
   }

   // Run game until no more lives left, or game cancelled by user
   printf("Starting Game\n");
   while ((gameState.nLives > 0) && (gameState.isActive == true))
   {
      // Instantiate n asteroids, each with random position and velocity
      for ( int i = 0; i < nAsteroids; i++)
      {
         Eigen::Vector2d position(randomX(re), randomY(re));
         Eigen::Vector2d velocity(randomV(re), randomV(re));
         Asteroid *asteroid = new Asteroid(position, velocity); 
         gameObjects.push_back(asteroid);
      }
      
      // Run main game loop until all asteroids destroyed, no lives left, or
      // game cancelled by user
      while ((gameState.isActive == true)
             && (gameState.nLives > 0)
             && 0 < std::count_if(gameObjects.begin(), gameObjects.end(), 
                                  [](GameObject *go){return go->GetColliderType() 
                                     == GameObject::ColliderType::ASTEROID;}))
      {
         clock_t loopStart = clock();

         // Update all game objects
         for (std::vector<GameObject*>::iterator gameObject = gameObjects.begin();
            gameObject != gameObjects.end();
            ++gameObject)
         {
            (*gameObject)->Update(&gameState);
         }

         // Check for collisions
         for (int i = 0; i < gameObjects.size()-1; ++i)
         {
            for (int j = i+1; j < gameObjects.size(); ++j)
            {
               if (collisions::CheckCollision(gameObjects[i],
                                             gameObjects[j]) == true)
               {
                  gameObjects[i]->OnCollisionWith(gameObjects[j]->GetColliderType(), &gameState);
                  gameObjects[j]->OnCollisionWith(gameObjects[i]->GetColliderType(), &gameState);
               }
            }
         }
         
         // Compile lists of new objects to add and deactivated objects to remove
         std::queue<GameObject*> toAddQueue;
         std::queue<GameObject*> toRemoveQueue;
         for (std::vector<GameObject*>::iterator gameObject = gameObjects.begin();
            gameObject != gameObjects.end();
            ++gameObject)
         {
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
         }

         // Remove deactivated objects
         while (toRemoveQueue.size() > 0)
         {
            auto it = std::find(gameObjects.begin(), 
                              gameObjects.end(), 
                              toRemoveQueue.front()); 
            if (it != gameObjects.end())
            {
               delete *it;
               gameObjects.erase(it); 
            }
            toRemoveQueue.pop();
         }

         // Add newly-instantiated objects
         while (toAddQueue.size() > 0)
         {
            gameObjects.push_back(toAddQueue.front());
            toAddQueue.pop();
         }

         // Wait to draw next frame
         clock_t  elapsedTime = clock() - loopStart;
         float elapsedTime_ms = (clock() - loopStart) * (1000.0/CLOCKS_PER_SEC);
         if (elapsedTime_ms < 1000.0/gameState.GetFPS())
         {
            SDL_Delay(static_cast<int>(1000.0/gameState.GetFPS() - elapsedTime_ms));
         }

         // Clear screen and draw each currently-active object
         renderer.Clear();
         for (std::vector<GameObject*>::iterator gameObject = gameObjects.begin();
            gameObject != gameObjects.end();
            ++gameObject)
         {
            renderer.DrawObject(*gameObject);
         }
         renderer.Render();
      }
   } 

   // Game has ended - clean up
   printf("GAME OVER\n");
   renderer.Clear();
   for (std::vector<GameObject*>::iterator gameObject = gameObjects.begin();
      gameObject != gameObjects.end();
      ++gameObject)
   {
     delete *gameObject;
   }

}
