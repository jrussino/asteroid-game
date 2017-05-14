#include <random>
#include <stdio.h>  /* printf */ 
#include <vector>   /* vector */

#include <Eigen/Geometry>

#include "asteroid.h"
#include "player.h"
#include "renderer.h"

// Configurable stuff:
unsigned int nAsteroids = 5;        //# of asteroids per round
int asteroidRadius = 10;            //asteroid radius in pixels
unsigned int nShips = 3;            //number of player ships (aka how many times we can be hit before game ends)
unsigned int screenWidth = 640;     //width of game area in pixels
unsigned int screenHeight = 480;    //height of game area in pixels
double vMax = 2.0;                  //max asteroid speed TODO proper units

//Random value generators
std::uniform_real_distribution<double> randomX(0, screenWidth);
std::uniform_real_distribution<double> randomY(0, screenHeight);
std::uniform_real_distribution<double> randomV(-vMax, vMax);
std::default_random_engine re;


//Dummy controller - just handles QUIT signal (from ctrl+C or window close)
SDL_Event e;
bool dummy_controller()
{
    bool quit = false;

    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            quit = true;
        }
    }

    return quit;
}


int main( int argc, char* argv[] )
{
    printf("Starting Game\n");

    // Instantiate renderer
    Renderer renderer = Renderer(screenWidth, screenHeight);

    // Instantiate ship at center of screen
    std::vector<GameObject> gameObjects;
    Player player = Player(Eigen::Vector2d(screenWidth/2, screenHeight/2));
    gameObjects.push_back(player);

    // Instantiate n asteroids, each with random position and velocity
    for( int i = 0; i < nAsteroids; i++)
    {
        Eigen::Vector2d position(randomX(re), randomY(re));
        Eigen::Vector2d velocity(randomV(re), randomV(re));
        Asteroid asteroid = Asteroid(position, velocity, asteroidRadius); 
        gameObjects.push_back(asteroid);
    }

    // Run until no more lives left
    bool quit = false;
    while( (nShips > 0) && (quit == false))
    {
        //Apply control inputs
        quit = dummy_controller();

        //Update positions of all game objects and redraw
        renderer.Clear();
        for(std::vector<GameObject>::iterator gameObject = gameObjects.begin(); gameObject != gameObjects.end(); ++gameObject)
        {
            gameObject->Update(screenWidth, screenHeight);
            renderer.DrawObject(&*gameObject);
        }
        renderer.Render();
        SDL_Delay(30);//TODO (1/framerate - elapsed_time)
    }

    renderer.Clear();

    printf("GAME OVER\n");
}
