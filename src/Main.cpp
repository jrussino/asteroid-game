#include <random>
#include <stdio.h>
#include <vector>

#include <Eigen/Geometry>

#include "Asteroid.hpp"
#include "Controller.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "GameObject.hpp"
#include "KeyboardController.hpp"
#include "Player.hpp"

// Configurable stuff:
unsigned int nAsteroids = 5;        //# of asteroids per round
int asteroidRadius = 10;            //asteroid radius in pixels
unsigned int nShips = 3;            //number of player ships (aka how many times we can be hit before game ends)
unsigned int screenWidth = 640;     //width of game area in pixels
unsigned int screenHeight = 480;    //height of game area in pixels
double vMax = 2.0;                  //max asteroid speed TODO proper units
unsigned int fps = 60;              //frames to render per second

//Random value generators
std::uniform_real_distribution<double> randomX(0, screenWidth);
std::uniform_real_distribution<double> randomY(0, screenHeight);
std::uniform_real_distribution<double> randomV(-vMax, vMax);
std::default_random_engine re;


int main( int argc, char *argv[] )
{

    // Create new game
    GameState gameState(nShips, fps, screenWidth, screenHeight);
    Game game(gameState);

    // Instantiate ship at center of screen
    KeyboardController *controller = new KeyboardController();
    Player *player = new Player(Eigen::Vector2d(screenWidth/2, screenHeight/2), controller);
    game.AddObject(player);

    // Instantiate n asteroids, each with random position and velocity
    for( int i = 0; i < nAsteroids; i++)
    {
        Eigen::Vector2d position(randomX(re), randomY(re));
        Eigen::Vector2d velocity(randomV(re), randomV(re));
        Asteroid *asteroid = new Asteroid(position, velocity, asteroidRadius); 
        game.AddObject(asteroid);
    }

    // Run game
    printf("Starting Game\n");
    game.Run();
    printf("GAME OVER\n");
}
