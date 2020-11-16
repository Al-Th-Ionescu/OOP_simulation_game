#ifndef MAIN_CPP_WEAPONS_H
#define MAIN_CPP_WEAPONS_H

#include <iostream>
#include <string>

class weapon {
    std::string name;
    int min_dmg{};
    int max_dmg{};
    int durability{};
public:

    weapon();

    ~weapon() = default;

    void GetWeapon();

    int ReturnDmg() const;

    void SetDurability();

    void Use();

    int ReturnDur() const;

    std::string ReturnWeap();

    void BreakWeapon();

    void init();
};


#endif //MAIN_CPP_WEAPONS_H
