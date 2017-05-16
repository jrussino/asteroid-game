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
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>

class GameState
{
   public:
   GameState(int nLive, int fps, int screenWidth, int screenHeight);
   ~GameState();

   int getScreenWidth();
   int getScreenHeight();

   int nLives;
   int score;
   bool active;
   int fps;

   int screenWidth;
   int screenHeight;
};

#endif // GAME_STATE_H
