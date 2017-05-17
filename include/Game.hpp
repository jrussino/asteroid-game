//------------------------------------------------------------------------------
//                                 Game 
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
 * Handles game execution.
 */
//------------------------------------------------------------------------------
#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "GameObject.hpp"
#include "GameState.hpp"
#include "Renderer.hpp"

namespace asteroid_game {

class Game
{
   public:
   Game(GameState &gameState);
   ~Game();
   
   void AddObject(GameObject *gameObject);
   void Run();

   private:
   Game();
   Game(const Game &game);
   Game & operator=(const Game &game);

   GameState &state;
   Renderer renderer;
   std::vector<GameObject*> gameObjects;
   
};

} // namespace asteroid_game

#endif // Game_hpp
