#include "Monster.h"
#include "VariousMonsters.h"
#include "Smombi.h"
#include "SuperJiangshi.h"
#include "MyMonster.h"
#include <vector>

void MonsterWorld(std::vector<Monster*>& monsters) {
    for (int i = 0; i < 5; ++i) {
        for (auto m : monsters) {
            m->move();
            m->draw();
        }
        std::cout << "------------\n";
    }
}
