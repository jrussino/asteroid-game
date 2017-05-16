//------------------------------------------------------------------------------
//                            Keyboard Controller
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Controls player object via keyboard input
 */
//------------------------------------------------------------------------------
#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "Controller.hpp"

#include <SDL2/SDL.h>

class KeyboardController : public Controller
{
   public:
   KeyboardController();
   ~KeyboardController();
   std::vector<Controller::Command> Update();

   private:
   SDL_Event event;
};
#endif // KEYBOARD_CONTROLLER_H
