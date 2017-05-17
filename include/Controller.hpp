//------------------------------------------------------------------------------
//                                 Controller 
//------------------------------------------------------------------------------
// This file is part of asteroid-game
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
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
