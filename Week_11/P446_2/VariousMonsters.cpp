#include "VariousMonsters.h"
#include <iostream>

Zombie::Zombie(std::string n, int x, int y) : Monster(n, x, y) {}
void Zombie::move() {
    y += 1;
}

Vampire::Vampire(std::string n, int x, int y) : Monster(n, x, y) {}
void Vampire::move() {
    if (x < 10) x++;
    if (y < 10) y++;
}

Jiangshi::Jiangshi(std::string n, int x, int y, bool r) : Monster(n, x, y), right(r) {}
void Jiangshi::move() {
    if (right) x++;
    else x--;
}
