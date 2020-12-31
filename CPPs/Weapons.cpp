#include <iostream>
#include "../Headers/Weapons.h"

weapon::weapon() {
    durability=100;
}

weapon::~weapon()= default;

void weapon::Use(){
    durability=durability- (rand()%8);
}

int weapon::GetDurability() {
    return durability;
}


void weapon::ShowDurability() {
    std::cout<<durability;
}
void weapon::init() {
    std::cout << "You do not have any weapon so you'll use your fists! " << '\n' << '\n';
    durability=INT16_MAX;
}

void weapon::BreakWeapon() {
    if (durability <= 0) {
        std::cout << '\n' << "Your weapon has broken!" << '\n';
        init();
    }
}

void weapon::ShowRemain() {
    std::cout << " has " << durability << " durability left"
              << '\n';
}

void weapon::UseNotBroken() {
    Use();
    BreakWeapon();
    ShowRemain();
}



