//------------------------------------------------------------------------------
//                                  GameState 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Provides game configuration and state information
 */
//------------------------------------------------------------------------------
#include "GameState.hpp"

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
   fps(30),
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
