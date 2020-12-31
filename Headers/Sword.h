#ifndef MAIN_CPP_SWORD_H
#define MAIN_CPP_SWORD_H

#include "Weapons.h"

class sword: public weapon{
    std::string name;
    int min_dmg{};
    int max_dmg{};
public:
    sword();
    ~sword()=default;
    void ShowDurability();
    int ReturnDmg();
    std::string ReturnWeap();
    void BreakWeapon();
    int ReturnMinDmg();
    void ShowRemain();
    void UseNotBroken();
};

#endif //MAIN_CPP_SWORD_H
