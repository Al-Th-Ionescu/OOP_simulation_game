#include <iostream>
#include "../Headers/Weapons.h"

weapons::weapons() {
    int random = rand() % 4;
    switch (random) {
        case 0:
            this->name = "stick";
            std::cout << '\n' << "You have found a " << this->name << ". Use it wisely." << '\n';
            this->min_dmg = rand() % 10 + 1;
            this->max_dmg = min_dmg + 15;

            break;
        case 1:
            this->name = "sword";
            std::cout << '\n' << "You have found a " << this->name << ". Careful not to cut yourself!" << '\n';
            this->min_dmg = rand() % 25 + 1;
            this->max_dmg = min_dmg + 10;
            break;
        case 2:
            this->name = "bow";
            std::cout << '\n' << "You have found a " << this->name << ". Make the arrows rain!" << '\n';
            this->min_dmg = rand() % 35 + 1;
            this->max_dmg = min_dmg + 20;
            break;
        case 3:
            this->name = "dagger";
            std::cout << '\n' << "You have found a " << this->name << ". Stab the enemies from behind!" << '\n';
            this->min_dmg = rand() % 15 + 1;
            this->max_dmg = min_dmg + 5;
            break;
        default: break;
    }
    std::cout<<"The "<<this->name<<"'s dmg is "<<this->min_dmg<<"-"<<this->max_dmg<<'\n';
}
weapons::~weapons() {
    if (durability <= 0)
        std::cout<< '\n' << "Look like your weapon broke and vanished into the void." << '\n';
}

int weapons::ReturnDmg() const {
    return (min_dmg + rand() % (max_dmg -min_dmg) + 1 );
}

void weapons::Use()
{
    durability=durability - (rand() % 9) ;
}

int weapons::ReturnDur() const {
    return durability;
}

std::string weapons::ReturnWeap() {
    return name;
}

