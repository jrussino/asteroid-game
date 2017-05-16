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

GameState::GameState(int nLives, int fps, int screenWidth, int screenHeight) :
   nLives(nLives),
   score(0),
   active(true),
   fps(30),
   screenWidth(screenWidth),
   screenHeight(screenHeight)
{
}

GameState::~GameState()
{
}
