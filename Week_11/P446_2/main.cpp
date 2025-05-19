#include "Monster.h"
#include "VariousMonsters.h"
#include "Smombi.h"
#include "SuperJiangshi.h"
#include "MyMonster.h"
#include <vector>
#include "MonsterWorldGame.h"


extern void MonsterWorld(std::vector<Monster*>& monsters);

int main() {
    std::vector<Monster*> monsters;
    monsters.push_back(new Zombie("Zombie1", 0, 0));
    monsters.push_back(new Vampire("Vampire1", 5, 5));
    monsters.push_back(new Jiangshi("Jiangshi1", 10, 10, true));
    monsters.push_back(new Smombi("Smombi1", 3, 0));
    monsters.push_back(new SuperJiangshi("SuperJiangshi1", 7, 7, false));
    monsters.push_back(new MyMonster("MyMonster1", 8, 8));

    MonsterWorld(monsters);

    for (auto m : monsters) delete m;
    return 0;
}
