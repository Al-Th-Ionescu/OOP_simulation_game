#include <iostream>
#include <string>
#include "../Headers/Stick.h"

stick::stick() {
    this->name = "stick";
    std::cout << "\nYou have found a stick and you can use it as weapon!\n";
    this->min_dmg = rand() % 10 + 1;
    this->max_dmg = min_dmg + 15;
    std::cout << '\n' << "Your " << this->name << " has " << this->min_dmg << "-" << this->max_dmg << " dmg." << '\n';
}

void stick::Use() {
    weapon::Use();
}

int stick::GetDurability() {
    weapon::GetDurability();
}

void stick::ShowDurability() {
    std::cout << "\nYour " << name << " has ";
    weapon::ShowDurability();
    std::cout << " durability left\n";
}


int stick::ReturnDmg() {
    return (min_dmg + rand() % (max_dmg - min_dmg) + 1);
}

std::string stick::ReturnWeap() {
    return name;
}

void stick::BreakWeapon() {
    weapon::BreakWeapon();
    if (weapon::GetDurability() > 100) {
        min_dmg = 0;
        max_dmg = 5;
    }
}

int stick::ReturnMinDmg() {
    return min_dmg;
}


