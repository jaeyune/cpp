#pragma once
#include <string>

class Monster {
protected:
    std::string name;
    int x, y;
public:
    Monster(std::string name, int x, int y);
    virtual ~Monster();
    virtual void move() = 0;
    virtual void printInfo() const;
};
