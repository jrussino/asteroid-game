#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>

#include "gameObject.h"

class Asteroid : public GameObject
{
    public:
    Asteroid(std::vector<double> position, std::vector<double> velocity, int radius);
    ~Asteroid();

    private:
    int radius;
    std::vector<double> position;
    std::vector<double> velocity;
};

#endif // ASTEROID_H
