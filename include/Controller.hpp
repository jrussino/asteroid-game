//------------------------------------------------------------------------------
//                                 Controller 
//------------------------------------------------------------------------------
// Asteroid-Game 
//
// ** TODO LICENSE **
// 
// Author: Joseph A. Russino
// Created: 2017/05/13
//
/**
 * Base class for objects that control the player object
 */
//------------------------------------------------------------------------------
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
