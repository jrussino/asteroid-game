TARGET=asteroid-game

CXX=g++
CPPFLAGS=-std=c++11 -Iinclude `pkg-config --cflags eigen3`
LIBS=`sdl2-config --libs` -lSDL2_gfx

SRCS=$(wildcard src/*.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CPPFLAGS) $(SRCS) -o bin/$(TARGET) $(LIBS)
