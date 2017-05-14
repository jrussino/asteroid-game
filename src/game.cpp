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
    std::queue<GameObject*> toAddQueue;
    std::queue<GameObject*> toRemoveQueue;
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
                toAddQueue.push(*newObject);
            }
            if((*gameObject)->IsActive() == false)
            {
                toRemoveQueue.push(*gameObject);
            }
            else
            {
                renderer.DrawObject(*gameObject);
            }
        }
        renderer.Render();
        // Remove inactive objects
        while(toRemoveQueue.size() > 0)
        {
            auto it = std::find(gameObjects.begin(), gameObjects.end(), toRemoveQueue.front()); 
            if (it != gameObjects.end())
            {
                gameObjects.erase(it); 
            }
            toRemoveQueue.pop();
        }
        // Add new objects
        while(toAddQueue.size() > 0)
        {
            gameObjects.push_back(toAddQueue.front());
            toAddQueue.pop();
        }
        SDL_Delay(30);//TODO (1/framerate - elapsed_time)
   } 
}
