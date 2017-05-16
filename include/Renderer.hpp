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
#ifndef RENDERER_H
#define RENDERER_H

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

   bool initialized;

   private:
   Renderer();
   Renderer(const Renderer &renderer);
   Renderer & operator=(const Renderer &renderer);

   void Init();

   int screenWidth;  // screen width (in pixels)
   int screenHeight; // screen height (in pixels)

   
   SDL_Window *sdlWindow = NULL;     // the window we'll be rendering to
   SDL_Renderer *sdlRenderer = NULL; // the renderer - renders images to the window
};

#endif // RENDERER_H
