#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include <Eigen/Geometry>


class GameObject
{
    public:
    GameObject(Eigen::Vector2d position);
    virtual ~GameObject();
    virtual void Update(int screenWidth, int screenHeight);
    Eigen::Vector2i GetPos();
//    virtual std::pair<short int*, short int*> GetPolygon() = 0;

    protected:
    Eigen::Vector2d velocity;

    private:
    Eigen::Vector2d position;
};

#endif // GAMEOBJECT_H
