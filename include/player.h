#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "gameObject.h"

class Player : public GameObject
{
    public:
    Player(std::vector<double> position);
    ~Player();
};

#endif // PLAYER_H
