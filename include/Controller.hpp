#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>

class Controller
{
    public:
    Controller();
    ~Controller();
    enum Command {TURN_LEFT, TURN_RIGHT, THRUST, FIRE, QUIT};
    virtual std::vector<Command> Update() = 0;
};

#endif // CONTROLLER_H
