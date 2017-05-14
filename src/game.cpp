#include "game.h"

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
    while( (state.nLives > 0) && (state.active == true) )
    {
        //Update positions of all game objects and redraw
        renderer.Clear();
        for(std::vector<GameObject*>::iterator gameObject = gameObjects.begin(); gameObject != gameObjects.end(); ++gameObject)
        {
            (*gameObject)->Update(&state);
            renderer.DrawObject(*gameObject);
        }
        renderer.Render();
        SDL_Delay(30);//TODO (1/framerate - elapsed_time)
   } 
}
