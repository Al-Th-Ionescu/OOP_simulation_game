#include <iostream>
#include "../Headers/Weapons.h"

weapon::weapon() {
}

void weapon::init() {
    std::cout << "You do not have any weapon so you'll use your fists! " << '\n' << '\n';
    this->name = "fist";
    this->min_dmg = 1;
    this->max_dmg = 5;
    this->durability = INT32_MAX;
}

void weapon::GetWeapon() {
    std::cout << '\n' << '\n' << "Congratulations! You have found a weapons!" << '\n' << '\n';
    std::cout << "<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << '\n';
    int random = rand() % 4;
    switch (random) {
        case 0:
            this->name = "stick";
            std::cout << '\n' << "You have found a " << this->name << ". Use it wisely." << '\n';
            this->min_dmg = rand() % 10 + 1;
            this->max_dmg = min_dmg + 15;
            SetDurability();
            break;
        case 1:
            this->name = "sword";
            std::cout << '\n' << "You have found a " << this->name << ". Careful not to cut yourself!" << '\n';
            this->min_dmg = rand() % 25 + 1;
            this->max_dmg = min_dmg + 10;
            SetDurability();
            break;
        case 2:
            this->name = "bow";
            std::cout << '\n' << "You have found a " << this->name << ". Make the arrows rain!" << '\n';
            this->min_dmg = rand() % 35 + 1;
            this->max_dmg = min_dmg + 20;
            SetDurability();
            break;
        case 3:
            this->name = "dagger";
            std::cout << '\n' << "You have found a " << this->name << ". Stab the enemies from behind!" << '\n';
            this->min_dmg = rand() % 15 + 1;
            this->max_dmg = min_dmg + 5;
            SetDurability();
            break;
        default:
            break;
    }
    std::cout << '\n' << "Your " << this->name << " has " << this->min_dmg << "-" << this->max_dmg << " dmg." << '\n';
}

void weapon::SetDurability() {
    this->durability = 100;
}

int weapon::ReturnDmg() const {
    return (min_dmg + rand() % (max_dmg - min_dmg) + 1);
}

void weapon::Use() {
    if (this->name != "fist")
        durability = durability - (rand() % 8);
}

int weapon::ReturnDur() const {
    return durability;
}

std::string weapon::ReturnWeap() {
    return name;
}

void weapon::BreakWeapon() {
    if (durability <= 0) {
        std::cout << '\n' << "Your weapon has broken!" << '\n';
        init();
    }
}


