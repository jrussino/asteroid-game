#include "asteroid.h"


Asteroid::Asteroid(std::vector<double> position, std::vector<double> velocity, int radius) :
    GameObject(position)
{
    this->velocity = velocity;
}

Asteroid::~Asteroid()
{
}
