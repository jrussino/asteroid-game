//------------------------------------------------------------------------------
//                                  GameState 
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
 * Provides game configuration and state information
 */
//------------------------------------------------------------------------------
#ifndef GAME_State_hpp
#define GAME_State_hpp

#include <vector> // vector

class GameState
{
   public:
   GameState(int nLives, int fps, int screenWidth, int screenHeight);
   ~GameState();

   int GetFPS();
   int GetScreenWidth();
   int GetScreenHeight();

   int nLives;    // number of lives remaining
   int score;     // current score
   bool isActive; // whether the game should continue

   private:
   GameState();
   GameState(const GameState &gameState);
   GameState & operator=(const GameState &gameState);

   const int fps;          // frames per second - how frequently to render images
   const int screenWidth;  // screen width (in pixels)
   const int screenHeight; // screen height (in pixels)

};

#endif // GAME_State_hpp
