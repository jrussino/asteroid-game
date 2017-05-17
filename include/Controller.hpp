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
#ifndef Controller_hpp
#define Controller_hpp

#include <vector>

class Controller
{
   public:
   Controller();
   virtual ~Controller();

   enum Command {TURN_LEFT, TURN_RIGHT, THRUST, FIRE, QUIT}; // set of possible commands

   //---------------------------------------------------------------------------
   // virtual std::vector<Command> ~Update()
   //---------------------------------------------------------------------------
   /**
   * Gets the set of commands for a given step of the simulation.
   *
   * @note pure virtual - Controller cannot be instantiated; derived classes
   * must implement this
   */
   //---------------------------------------------------------------------------
   virtual std::vector<Command> Update() = 0;

   private:
   Controller(const Controller &controller);
   Controller & operator=(const Controller &controller);
};

#endif // Controller_hpp
