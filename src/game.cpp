#include "game.h"

#include <queue>

Game::Game(GameState gameState) :
    state(gameState),
    renderer(gameState.screenWidth, gameState.screenHeight)
{
}

Game::~Game()
{
    renderer.Clear();

    for(std::vector<GameObject*>::iterator gameObject = gameObjects.begin(); gameObject != gameObjects.end(); ++gameObject)
    {
        delete *gameObject;
    }
}

void Game::AddObject(GameObject* gameObject)
{
    gameObjects.push_back(gameObject);
}

void Game::Run()
{
    // Run until no more lives left
    std::queue<GameObject*> newObjectQueue;
    while( (state.nLives > 0) && (state.active == true) )
    {
        //Update positions of all game objects and redraw
        std::vector<GameObject*> newObjects;
        renderer.Clear();
        for(std::vector<GameObject*>::iterator gameObject = gameObjects.begin(); gameObject != gameObjects.end(); ++gameObject)
        {
            (*gameObject)->Update(&state);
            std::vector<GameObject*> newObjects = (*gameObject)->GetNewObjects();
            for(std::vector<GameObject*>::iterator newObject = newObjects.begin(); newObject != newObjects.end(); ++newObject)
            {
                newObjectQueue.push(*newObject);
            }
            
            renderer.DrawObject(*gameObject);
        }
        renderer.Render();
        // Add new objects to the list
        while(newObjectQueue.size() > 0)
        {
            gameObjects.push_back(newObjectQueue.front());
            newObjectQueue.pop();
        }
        SDL_Delay(30);//TODO (1/framerate - elapsed_time)
   } 
}
