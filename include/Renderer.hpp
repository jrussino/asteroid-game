//------------------------------------------------------------------------------
//                                 Renderer 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
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

#endif // Renderer_hpp
