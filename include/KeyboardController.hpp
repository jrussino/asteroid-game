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
#ifndef KEYBOARD_Controller_hpp
#define KEYBOARD_Controller_hpp

#include "Controller.hpp"

#include <SDL2/SDL.h>

class KeyboardController : public Controller
{
   public:
   KeyboardController();
   ~KeyboardController();
   std::vector<Controller::Command> Update();

   private:
   KeyboardController(const KeyboardController &keyboardController);
   KeyboardController & operator=(const KeyboardController &keyboardController);

   SDL_Event event; // events from the SDL subsystem (used for keyboard events)
};

#endif // KEYBOARD_Controller_hpp
