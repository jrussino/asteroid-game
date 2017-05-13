#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

class GameObject
{
    public:
    GameObject(std::vector<double> position, std::vector<double> velocity);
    ~GameObject();
    void Update(int screenWidth, int screenHeight);
    std::vector<int> GetPos();

    private:
    std::vector<double> position;
    std::vector<double> velocity;
};

#endif // GAMEOBJECT_H
