#include "SuperJiangshi.h"

SuperJiangshi::SuperJiangshi(std::string n, int x, int y, bool r) : Jiangshi(n, x, y, r) {}

void SuperJiangshi::move() {
    tick++;
    if (tick % 3 == 0) {
        right = !right; // 방향 전환
    }
    Jiangshi::move();
}
