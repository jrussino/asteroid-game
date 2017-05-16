#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include <Eigen/Geometry>

#include "GameState.hpp"

class GameObject
{
   public:
   GameObject(Eigen::Vector2d position);
   virtual ~GameObject();
   virtual void Update(GameState *gameState);
   std::vector<GameObject*> GetNewObjects();
   Eigen::Vector2i GetPos();
   std::pair<std::vector<short int>, std::vector<short int> > GetPolygon();
   Eigen::Vector2d GetPosition();
   bool IsActive();

   protected:
   bool active;
   GameState *gameState;
   Eigen::Vector2d velocity;
   std::vector<Eigen::Vector2d> polygon;
   std::vector<GameObject*> newGameObjects;

   private:
   Eigen::Vector2d position;
};

#endif // GAMEOBJECT_H
