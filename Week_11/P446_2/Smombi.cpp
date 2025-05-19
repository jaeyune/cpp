#include "Smombi.h"
Smombi::Smombi(std::string n, int x, int y) : Monster(n, x, y) {}
void Smombi::move() {
    y += 1; // 세로 방향으로만 이동
}
