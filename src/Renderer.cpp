#include "Renderer.hpp"

#include <Eigen/Geometry>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


Renderer::Renderer(int width, int height) :
   screenWidth(width),
   screenHeight(height)
{
   Init();
   if (initialized == false)
   {
      printf("WARNING - failed to initialize renderer\n");
   }
}

Renderer::~Renderer()
{
   //Destroy window
   SDL_DestroyWindow(sdlWindow);

   //Quit SDL subsystem
   SDL_Quit();
}

void Renderer::Clear()
{
   //Clear screen
   SDL_SetRenderDrawColor(sdlRenderer, 0x00, 0x00, 0x00, 0xFF);
   SDL_RenderClear(sdlRenderer);

}

void Renderer::DrawObject(GameObject *gameObject)
{
   std::pair<std::vector<short int>,
           std::vector<short int> > verts = gameObject->GetPolygon();
   polygonColor(sdlRenderer,
             verts.first.data(),
             verts.second.data(),
             verts.first.size(),
             0xFFFFFFFF);
}

void Renderer::Render()
{
   //Update screen
   SDL_RenderPresent(sdlRenderer);
}

void Renderer::Init()
{
   initialized = true;

   //Initialize SDL
   if (SDL_Init(SDL_INIT_VIDEO) < 0)
   {
      printf("SDL could not initialize! SDL_Error: %s\n",  SDL_GetError());
   }
   else 
   {
      //Create window
      sdlWindow = SDL_CreateWindow("Asteroid-Game", 
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            screenWidth, screenHeight,
                            SDL_WINDOW_SHOWN);
      if (sdlWindow == NULL)
      {
         printf("Window could not be created! SDL_Error: %s\n",
               SDL_GetError());
         initialized = false;
      }
      else
      {
         //Create renderer for window
         sdlRenderer = SDL_CreateRenderer(sdlWindow,
                                  -1,
                                  SDL_RENDERER_ACCELERATED);
         if (sdlRenderer == NULL)
         {
            printf("Renderer could not be created! SDL Error: %s\n",
                  SDL_GetError());
            initialized = false;
         }
      }
   }

   return;
}
