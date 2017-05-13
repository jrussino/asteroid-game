all:
	g++ -std=c++11 main.cpp renderer.cpp asteroid.cpp gameObject.cpp `sdl2-config --libs` -lSDL2_gfx -o asteroid-game
