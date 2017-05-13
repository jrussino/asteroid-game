all:
	g++ -std=c++11 src/main.cpp src/renderer.cpp src/asteroid.cpp src/gameObject.cpp src/player.cpp `sdl2-config --libs` -lSDL2_gfx -o bin/asteroid-game -I include
