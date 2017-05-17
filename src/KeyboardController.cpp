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
#include "KeyboardController.hpp"

//-------------------------------
// public methods
//-------------------------------

//------------------------------------------------------------------------------
// KeyboardController()
//------------------------------------------------------------------------------
/**
 * Constructs a new Keyboard Controller object
 */
//------------------------------------------------------------------------------
KeyboardController::KeyboardController()
{
}

//------------------------------------------------------------------------------
// ~KeyboardController()
//------------------------------------------------------------------------------
/**
 * Destructor.
 */
//------------------------------------------------------------------------------
KeyboardController::~KeyboardController()
{
}

//------------------------------------------------------------------------------
// std::vector<Controller::Command> Update()
//------------------------------------------------------------------------------
/**
 * Checks keyboard state & events and commands changes in player velocity,
 * rotation, and/or firing.
 */
//------------------------------------------------------------------------------
std::vector<Controller::Command> KeyboardController::Update()
{
   std::vector<Controller::Command> commands;
   SDL_PumpEvents();

   const Uint8* keyboardState = SDL_GetKeyboardState(NULL); 
   if (keyboardState[SDL_SCANCODE_LEFT])
   {
      commands.push_back(Controller::Command::TURN_LEFT);
   }
   if (keyboardState[SDL_SCANCODE_RIGHT])
   {
      commands.push_back(Controller::Command::TURN_RIGHT);
   }
   if (keyboardState[SDL_SCANCODE_LCTRL])
   {
      commands.push_back(Controller::Command::FIRE);
   }
   if (keyboardState[SDL_SCANCODE_LALT])
   {
      commands.push_back(Controller::Command::THRUST);
   }
   
   //Handle events on queue
   while (SDL_PollEvent(&event) != 0)
   {
      //User requests quit
      if (event.type == SDL_QUIT)
      {
         commands.push_back(Controller::Command::QUIT);
      }
      //User presses a key
      else if (event.type == SDL_KEYDOWN)
      {
         if (event.key.keysym.sym == SDLK_ESCAPE)
         {
            commands.push_back(Controller::Command::QUIT);
         }
      }
   }

   return commands;
} 
