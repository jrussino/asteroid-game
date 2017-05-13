#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>

#include "gameObject.h"

class Asteroid : public GameObject
{
    public:
    Asteroid(std::vector<double> position, std::vector<double> velocity, int radius);
    ~Asteroid();
//    std::pair<short int*, short int*> GetPolygon();
};

#endif // ASTEROID_H
