#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"

class Controller
{
    public:
    Controller(Player* player);
    ~Controller();
    virtual bool Update() = 0;

    protected:
    Player* player;
};

#endif // CONTROLLER_H
