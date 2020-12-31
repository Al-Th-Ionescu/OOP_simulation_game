#include <iostream>
#include "../Headers/Sword.h"

sword::sword(){
    this->name = "sword";
    std::cout << "\nYou have found a rusty sword and you can use it as weapon!\n";
    this->min_dmg = rand() % 24 + 1;
    this->max_dmg = min_dmg + 10;
    std::cout << '\n' << "Your " << this->name << " has " << this->min_dmg << "-" << this->max_dmg << " dmg." << '\n';
}

void sword::ShowDurability() {
    std::cout << "\nYour rusty " << name << " has ";
        weapon::ShowDurability();
        std::cout << " durability left\n";
}

int sword::ReturnDmg() {
    return (min_dmg + rand() % (max_dmg - min_dmg) + 1);
}

std::string sword::ReturnWeap() {
    return name;
}

void sword::BreakWeapon() {
    weapon::BreakWeapon();
    if (weapon::GetDurability() > 100) {
        min_dmg = 0;
        max_dmg = 5;
    }
}

int sword::ReturnMinDmg() {
    return min_dmg;
}

void sword::ShowRemain() {
    if (min_dmg != 0)
    {
        std::cout<<'\n'<<"Your "<<name;
        weapon::ShowRemain();
    }
}

void sword::UseNotBroken() {
    if (min_dmg != 0)
        weapon::UseNotBroken();
}




