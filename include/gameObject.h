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
    std::pair<std::vector<short int>, std::vector<short int> > GetPolygon();

    protected:
    Eigen::Vector2d velocity;
    std::vector<Eigen::Vector2d> polygon;

    private:
    Eigen::Vector2d position;
};

#endif // GAMEOBJECT_H
