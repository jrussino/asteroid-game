#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>

class GameState
{
    public:
    GameState(int screenWidth, int screenHeight, int nLives);
    ~GameState();

    int nLives;
    int score;
    bool active;

    int screenWidth;
    int screenHeight;
};

#endif // GAME_STATE_H
