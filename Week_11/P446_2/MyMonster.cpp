#include "MyMonster.h"
#include <cstdlib>

MyMonster::MyMonster(std::string n, int x, int y) : Monster(n, x, y) {}

void MyMonster::move() {
    x += rand() % 3 - 1;
    y += rand() % 3 - 1;
}
