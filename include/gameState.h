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
