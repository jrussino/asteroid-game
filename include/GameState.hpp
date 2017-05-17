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
#ifndef GAME_State_hpp
#define GAME_State_hpp

#include <vector> // vector

class GameState
{
   public:
   GameState(int nLive, int fps, int screenWidth, int screenHeight);
   ~GameState();

   int getScreenWidth();
   int getScreenHeight();

   int nLives;    // number of lives remaining
   int score;     // current score
   bool isActive; // whether the game should continue
   int fps;       // frames per second - how frequently to render images

   int screenWidth;  // screen width (in pixels)
   int screenHeight; // screen height (in pixels)

   private:
   GameState();
   GameState(const GameState &gameState);
   GameState & operator=(const GameState &gameState);
};

#endif // GAME_State_hpp
