all:
	g++ -std=c++11 src/main.cpp src/renderer.cpp src/asteroid.cpp src/gameObject.cpp src/player.cpp src/bullet.cpp src/controller.cpp src/keyboardController.cpp src/game.cpp src/gameState.cpp `pkg-config --cflags eigen3` `sdl2-config --libs` -lSDL2_gfx -o bin/asteroid-game -I include
