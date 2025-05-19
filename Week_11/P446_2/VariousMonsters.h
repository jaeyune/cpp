#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
    Zombie(std::string n, int x, int y);
    void move() override;
};

class Vampire : public Monster {
public:
    Vampire(std::string n, int x, int y);
    void move() override;
};

class Jiangshi : public Monster {
    bool reverse;
public:
    Jiangshi(std::string n, int x, int y, bool r);
    void move() override;
};
