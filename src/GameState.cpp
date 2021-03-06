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
#include <iostream> // std::cout

#include "GameState.hpp"

namespace asteroid_game {

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// GameState(int nLives, int fps, int screenWidth, int screenHeight)
//------------------------------------------------------------------------------
/**
 * Constructs GameState object; initialized with game configuration.
 *
 * @param <nLives>       number of player lives - determines when game ends
 * @param <fps>          frames per second - descrinbe how long to delay between
 *                       rendering frames  
 * @param <screenWidth>  width of the game screen
 * @param <screenHeight> height of the game screen
 */
//------------------------------------------------------------------------------
GameState::GameState(int nLives, int fps, int screenWidth, int screenHeight) :
   nLives(nLives),
   score(0),
   isActive(true),
   fps(fps),
   screenWidth(screenWidth),
   screenHeight(screenHeight)
{
}

//------------------------------------------------------------------------------
// ~GameState()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
GameState::~GameState()
{
}

//------------------------------------------------------------------------------
// int GetFPS()
//------------------------------------------------------------------------------
/**
 * Accessor for fps (framerate) property
 *
 * @return int fps
 */
//------------------------------------------------------------------------------
int GameState::GetFPS()
{
   return fps;
}

//------------------------------------------------------------------------------
// int GetScreenWidth()
//------------------------------------------------------------------------------
/**
 * Accessor for screenWidth property
 *
 * @return int screenWidth
 */
//------------------------------------------------------------------------------
int GameState::GetScreenWidth()
{
   return screenWidth;
}

//------------------------------------------------------------------------------
// int GetScreenHeight()
//------------------------------------------------------------------------------
/**
 * Accessor for screenHeight property
 *
 * @return int screenHeight
 */
//------------------------------------------------------------------------------
int GameState::GetScreenHeight()
{
   return screenHeight;
}

//------------------------------------------------------------------------------
// void IncreaseScore(int amount=1)
//------------------------------------------------------------------------------
/**
 * Increases score by the specified amount
 *
 * @param amount - the amount by which to increase (default=1)
 */
//------------------------------------------------------------------------------
void GameState::IncreaseScore(int amount)
{
   score += amount;
   Print();
}

//------------------------------------------------------------------------------
// void DecreaseLives(int amount=1)
//------------------------------------------------------------------------------
/**
 * Decreases nLives by the amount specified
 *
 * @param amount - the amount by which to decrease (default=1)
 */
//------------------------------------------------------------------------------
void GameState::DecreaseLives(int amount)
{
   nLives -= amount;
   Print();
}

//------------------------------------------------------------------------------
// void Print()
//------------------------------------------------------------------------------
/**
 * Prints the current score and number of lives to stdout
 */
//------------------------------------------------------------------------------
void GameState::Print()
{
   std::cout << "LIVES: " << nLives << " | SCORE: " << score << std::endl;
}

} // namespace asteroid_game
