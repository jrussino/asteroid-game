#include "keyboardController.h"

KeyboardController::KeyboardController(Player* player) :
    Controller(player)
{
}

KeyboardController::~KeyboardController()
{
}

bool KeyboardController::Update()
{
    SDL_PumpEvents();

    const Uint8* keyboardState = SDL_GetKeyboardState(NULL); 
    if(keyboardState[SDL_SCANCODE_LEFT])
    {
        player->TurnLeft();
    }
    if(keyboardState[SDL_SCANCODE_RIGHT])
    {
        player->TurnRight();
    }
    if(keyboardState[SDL_SCANCODE_LCTRL])
    {
        player->Fire();
    }
    if(keyboardState[SDL_SCANCODE_LALT])
    {
        player->Thrust();
    }
    
    //Handle events on queue
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            return false;
        }
        //User presses a key
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return false;
            }
        }
    }

    return true;
}
