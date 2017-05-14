#include "gameState.h"

GameState::GameState(int nLives, int screenWidth, int screenHeight) :
    nLives(nLives),
    score(0),
    active(true),
    screenWidth(screenWidth),
    screenHeight(screenHeight)
{
}

GameState::~GameState()
{
}
