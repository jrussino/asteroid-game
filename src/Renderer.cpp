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

#include <iostream> // cerr

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
   screenHeight(height),
   initialized(false)
{
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
   if (initialized == true)
   {
      //Clear screen
      SDL_SetRenderDrawColor(sdlRenderer, 0x00, 0x00, 0x00, 0xFF);
      SDL_RenderClear(sdlRenderer);
   }
   else
   {
      std::cerr << "WARNING - attempting to clear window, but renderer is not initialized."
                << std::endl;
   }
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
   if (initialized == true)
   {
      std::pair<std::vector<short int>,
                std::vector<short int> > verts = gameObject->GetPolygon();
      polygonColor(sdlRenderer,
                   verts.first.data(),
                   verts.second.data(),
                   verts.first.size(),
                   0xFFFFFFFF);
   }
   else
   {
      std::cerr << "WARNING - attempting to draw object, but renderer is not initialized."
                << std::endl;
   }
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
// void Initialize()
//------------------------------------------------------------------------------
/**
 * Creates the game window and initiailzes the SDL renderer that will be used to
 * draw images to this window.
 *
 * @todo this should throw an exception if it fails; game can't proceed if we
 * can't render graphics.
 *
 * @note anything using Renderer MUST call this 
 */
//------------------------------------------------------------------------------
bool Renderer::Initialize()
{
   // Only initialize once
   if (initialized == true)
   {
      return true;
   }

   initialized = true;  // true unless one of the followinc checks fails

   //Initialize SDL
   if (SDL_Init(SDL_INIT_VIDEO) < 0)
   {
      std::cerr << "SDL could not initialize! SDL_Error: "
                << SDL_GetError()
                << std::endl;
      initialized = false;
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
         std::cerr << "Window could not be created! SDL_Error: "
                   << SDL_GetError()
                   << std::endl;
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
            std::cerr << "Renderer could not be created! SDL Error: "
                      << SDL_GetError()
                      << std::endl;
            initialized = false;
         }
      }
   }

   return initialized;
}
