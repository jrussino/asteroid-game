all:
	g++ -std=c++11 src/Main.cpp src/Renderer.cpp src/Asteroid.cpp src/GameObject.cpp src/Player.cpp src/Bullet.cpp src/Controller.cpp src/KeyboardController.cpp src/Game.cpp src/GameState.cpp `pkg-config --cflags eigen3` `sdl2-config --libs` -lSDL2_gfx -o bin/asteroid-game -I include
