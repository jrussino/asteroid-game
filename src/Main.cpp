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
#include <random>  // uniform_real_distribution, default_random_engine

#include <Eigen/Geometry>

#include "Asteroid.hpp"
#include "Controller.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "GameObject.hpp"
#include "KeyboardController.hpp"
#include "Player.hpp"

// Configurable stuff:
unsigned int nAsteroids = 5;     // # of asteroids per round
unsigned int nShips = 3;         // number of player ships (aka how many times we can be hit before game ends)
unsigned int screenWidth = 640;  // width of game area (in pixels)
unsigned int screenHeight = 480; // height of game area (in pixels)
double vMax = 2.0;               // max asteroid speed (in pixels/second)
unsigned int fps = 60;           // frames to render per second

//Random value generators
std::uniform_real_distribution<double> randomX(0, screenWidth);
std::uniform_real_distribution<double> randomY(0, screenHeight);
std::uniform_real_distribution<double> randomV(-vMax, vMax);
std::default_random_engine re;


int main( int argc, char *argv[] )
{

   // Create new game
   GameState gameState(nShips, fps, screenWidth, screenHeight);
   Game game(gameState);

   // Instantiate ship at center of screen
   KeyboardController *controller = new KeyboardController();
   Player *player = new Player(Eigen::Vector2d(screenWidth/2, screenHeight/2),
                        controller);
   game.AddObject(player);

   // Instantiate n asteroids, each with random position and velocity
   for ( int i = 0; i < nAsteroids; i++)
   {
      Eigen::Vector2d position(randomX(re), randomY(re));
      Eigen::Vector2d velocity(randomV(re), randomV(re));
      Asteroid *asteroid = new Asteroid(position, velocity); 
      game.AddObject(asteroid);
   }

   // Run game
   printf("Starting Game\n");
   game.Run();
   printf("GAME OVER\n");
}
