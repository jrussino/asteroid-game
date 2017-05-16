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
