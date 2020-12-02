#ifndef MAIN_CPP_SPECIALWEAPON_H
#define MAIN_CPP_SPECIALWEAPON_H

#include "Weapons.h"
#include "Status.h"

class SpecialWeapon : public weapon {
    std::string name;
    int min_dmg{};
    int max_dmg{};
public:
    void GetWeapon(weapon &, Status &);

    int ReturnDmg() const;
};

#endif //MAIN_CPP_SPECIALWEAPON_H
