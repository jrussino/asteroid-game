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
   void Init();

   //Screen dimensions
   int screenWidth;
   int screenHeight;

   //The window we'll be rendering to
   SDL_Window *sdlWindow = NULL;

   //The window renderer
   SDL_Renderer *sdlRenderer = NULL;
};

#endif // RENDERER_H
