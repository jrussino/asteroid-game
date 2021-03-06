//------------------------------------------------------------------------------
//                            Keyboard Controller
//------------------------------------------------------------------------------
// This file is part of asteroid-game
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
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

namespace asteroid_game {

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

} // namesace asteroid_game

#endif // KEYBOARD_Controller_hpp
