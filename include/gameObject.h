#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>


class GameObject
{
    public:
    GameObject(std::vector<double> position);
    ~GameObject();
    void Update(int screenWidth, int screenHeight);
    std::vector<int> GetPos();
//    virtual std::pair<short int*, short int*> GetPolygon() = 0;

    protected:
    std::vector<double> position;
    std::vector<double> velocity;
};

#endif // GAMEOBJECT_H
