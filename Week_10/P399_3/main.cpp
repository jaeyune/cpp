#include <iostream>
#include <vector>

using namespace std;

class Monster 
{
private:
    int x, y;
    int nEnergy;
    static int nCount;

public:
    Monster(int _x = 0, int _y = 0, int energy = 10) : x(_x), y(_y), nEnergy(energy) 
    {
        nCount++;
    }

    ~Monster() 
    {
        nCount--;
    }

    void eat() 
    {
        nEnergy += 5;
    }

    void decreaseEnergy() 
    {
        nEnergy--;
    }

    int getEnergy() const 
    
        return nEnergy;
    }

    void print() const 
    {
        cout << "몬스터 위치: (" << x << ", " << y << "), 에너지: " << nEnergy << endl;
    }

    static void printCount() 
    {
        cout << "전체 몬스터 수: " << nCount << endl;
    }

    static int getCount() 
    {
        return nCount;
    }
};

int Monster::nCount = 0;

class MonsterWorld 
{
private:
    vector<Monster*> pMon;

public:
    MonsterWorld(int n = 5) 
    {
        for (int i = 0; i < n; ++i)
            pMon.push_back(new Monster(i, i * 2, 10)); // 샘플 위치, 에너지
    }

    ~MonsterWorld() 
    {
        for (auto m : pMon) delete m;
    }

    void update() 
    {
        for (auto m : pMon)
            m->decreaseEnergy();
        checkStarvation();
        Monster::printCount();
    }

    void printMonsters() const 
    {
        for (auto m : pMon)
            m->print();
    }

    void checkStarvation() 
    {
        auto it = pMon.begin();
        while (it != pMon.end()) 
        {
            if ((*it)->getEnergy() <= 0) 
            {
                delete *it;
                it = pMon.erase(it);
            } else 
            {
                ++it;
            }
        }
    }
};

int main() 
{
    MonsterWorld world(3); // 몬스터 3마리로 시작

    for (int i = 0; i < 10; ++i) 
    {
        cout << "\n===== 턴 " << i + 1 << " =====" << endl;
        world.update();
        world.printMonsters();
    }

    return 0;
}
