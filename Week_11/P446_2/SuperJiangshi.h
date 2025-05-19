#ifndef SUPER_JIANGSHI_H
#define SUPER_JIANGSHI_H

#include "VariousMonsters.h"

class SuperJiangshi : public Jiangshi {
private:
    int tick = 0;

public:
    SuperJiangshi(std::string n, int x, int y, bool r);
    void move() override;
};

#endif
