//------------------------------------------------------------------------------
//                                 Renderer 
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
 * Creates game window and renders graphical representations of game objects
 */
//------------------------------------------------------------------------------
#ifndef Renderer_hpp
#define Renderer_hpp

#include <SDL2/SDL.h>
#include "GameObject.hpp"

namespace asteroid_game {

class Renderer
{
   public:
   Renderer(int width, int height);
   ~Renderer();
   void Clear();
   void DrawObject(GameObject *gameObject);
   void Render();
   bool Initialize();

   private:
   Renderer();
   Renderer(const Renderer &renderer);
   Renderer & operator=(const Renderer &renderer);

   const int screenWidth;  // screen width (in pixels)
   const int screenHeight; // screen height (in pixels)

   bool initialized; // True if window and renderer successfully created
   
   SDL_Window *sdlWindow = NULL;     // the window we'll be rendering to
   SDL_Renderer *sdlRenderer = NULL; // the renderer - renders images to the window
};

} // namespace asteroid_game

#endif // Renderer_hpp
