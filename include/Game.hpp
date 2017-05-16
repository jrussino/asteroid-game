#ifndef GAME_H
#define GAME_H

#include <vector>

#include "GameObject.hpp"
#include "GameState.hpp"
#include "Renderer.hpp"

class Game
{
    public:
    Game(GameState gameState);
    ~Game();
    
    void AddObject(GameObject *gameObject);
    void Run();

    private:
    GameState state;
    Renderer renderer;
    std::vector<GameObject*> gameObjects;
    
};

#endif // GAME_H