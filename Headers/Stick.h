#ifndef MAIN_CPP_STICK_H
#define MAIN_CPP_STICK_H

#include "Weapons.h"


class stick : public weapon {
    std::string name;
    int min_dmg{};
    int max_dmg{};
public:
    stick();
    ~stick()=default;
    void ShowDurability();
    int ReturnDmg();
    std::string ReturnWeap();
    void BreakWeapon();
    int ReturnMinDmg();
    void ShowRemain();
    void UseNotBroken();
};

#endif //MAIN_CPP_STICK_H
