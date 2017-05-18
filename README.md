# INTRODUCTION
asteroid-game

A bare-bones clone of the popular video game "Asteroids".

Simply `make` from the root directory,  and then run `./bin/asteroid-game` from
the command line to play.

# REQUIREMENTS
This software has been tested under Ubuntu 16.04. It requires the following
packages to compile:
* libsdl2-dev        (SDL2, for basic graphics)
* libsdl2-gfx-dev    (SDL2-gfx, for geometric primitives) 
* libeigen3-dev      (Eigen3, for linear algebra primitives and operations)

# DEFAULT CONTROLS
* Turn Right (clockwise) - Right arrow
* Turn Left (counter-clockwise) - Left arrow
* Thrust - left Alt
* Fire - left Ctrl

# INCLUDED FILES
* Asteroid.cpp/.hpp - Asteroid (implementation of GameObject). Increases score
  on collision with Bullet or Player.
* Bullet.cpp/.hpp - Bullet (implementation of GameObject). Instantiated by
  Player upon firing.
* Controller.cpp/.hpp - Abstract base class for things that control the Player.
* Collisions.cpp/.hpp - Namespace containing methods related to collision
  detection.
* GameObject.cpp/.hpp - Abstract base class for objects in the game.
* GameState.cpp/.hpp - Stores and controls access to game configuration and 
  state data.
* KeyboardController.cpp/.hpp - Controller implementation that uses keyboard
  input to control the player object.
* Main.cpp - Main procedure. Sets up and runs the game.
* Player.cpp/.hpp - Player (implementation of GameObject). Moves and fires in
  accordance with commands from a Controller. Decrements lives on collision with
  Asteroid.
* Renderer.cpp/.hpp - Graphics renderer. Creates game window and draws
  GameObjects every frame.


# ADDITIONAL NOTES
This project follows this NASA C++ coding standard and style guide:
https://ntrs.nasa.gov/search.jsp?R=20080039927


# AUTHOR
Joseph A. Russino

# LICENSE
GNU General Public License v3.0
(see LICENSE file)
