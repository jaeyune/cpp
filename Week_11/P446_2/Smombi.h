#ifndef SMOMBI_H
#define SMOMBI_H

#include "Monster.h"

class Smombi : public Monster {
public:
    Smombi(std::string n, int x, int y);
    void move() override;
};

#endif
