#include "Monster.h"
#include <iostream>

Monster::Monster(std::string name, int x, int y) : name(name), x(x), y(y) {}
Monster::~Monster() {}

void Monster::printInfo() const {
    std::cout << name << " at (" << x << ", " << y << ")" << std::endl;
}
