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
#include "Renderer.hpp"

#include <Eigen/Geometry>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


//------------------------------------------------------------------------------
// Renderer(int screenWidth, int screenHeight)
//------------------------------------------------------------------------------
/**
 * Constructs renderer object with specified window dimensions.
 *
 * @param <screenWidth>  width of the game screen
 * @param <screenHeight> height of the game screen
 */
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// ~Renderer()
//------------------------------------------------------------------------------
/**
 * Destructor.
 * Destroys the SDL window and quits the SDL subsystem 
 */
//------------------------------------------------------------------------------
Renderer::~Renderer()
{
   SDL_DestroyWindow(sdlWindow);
   SDL_Quit();
}

//------------------------------------------------------------------------------
// void Clear()
//------------------------------------------------------------------------------
/**
 * Clears the rendered image (to all black)
 *
 * @note typically used to clear the game screen before drawing a new frame
 */
//------------------------------------------------------------------------------
void Renderer::Clear()
{
   //Clear screen
   SDL_SetRenderDrawColor(sdlRenderer, 0x00, 0x00, 0x00, 0xFF);
   SDL_RenderClear(sdlRenderer);

}

//------------------------------------------------------------------------------
// void DrawObject(GameObject* gameObject)
//------------------------------------------------------------------------------
/**
 * Draws the game object's polygon to the game screen
 *
 * @param <gameObject> pointer to the game object to draw
 */
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// void Render()
//------------------------------------------------------------------------------
/**
 * Renders a new frame
 */
//------------------------------------------------------------------------------
void Renderer::Render()
{
   SDL_RenderPresent(sdlRenderer);
}

//------------------------------------------------------------------------------
// void Init()
//------------------------------------------------------------------------------
/**
 * Creates the game window and initiailzes the SDL renderer that will be used to
 * draw images to this window.
 *
 * @todo this should throw an exception if it fails; game can't proceed if we
 * can't render graphics.
 */
//------------------------------------------------------------------------------
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
