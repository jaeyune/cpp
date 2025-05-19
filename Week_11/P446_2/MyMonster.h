#ifndef MY_MONSTER_H
#define MY_MONSTER_H

#include "Monster.h"

class MyMonster : public Monster {
public:
    MyMonster(std::string n, int x, int y);
    void move() override;
};

#endif
