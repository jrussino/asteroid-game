#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "controller.h"

#include <SDL2/SDL.h>

class KeyboardController : public Controller
{
    public:
    KeyboardController(Player* player);
    ~KeyboardController();
    bool Update();

    private:
    SDL_Event event;
};
#endif // KEYBOARD_CONTROLLER_H
