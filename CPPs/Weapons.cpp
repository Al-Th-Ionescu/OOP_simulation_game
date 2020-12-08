#include <iostream>
#include "../Headers/Weapons.h"

weapon::weapon() {
    durability=100;
};

weapon::~weapon(){}

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


//            this->name = "sword";
//            std::cout << '\n' << "You have found a " << this->name << ". Careful not to cut yourself!" << '\n';
//            this->min_dmg = rand() % 25 + 1;
//            this->max_dmg = min_dmg + 10;
//            SetDurability();
//            break;
//        case 2:
//            this->name = "bow";
//            std::cout << '\n' << "You have found a " << this->name << ". Make the arrows rain!" << '\n';
//            this->min_dmg = rand() % 35 + 1;
//            this->max_dmg = min_dmg + 20;
//            SetDurability();
//            break;
//        case 3:
//            this->name = "dagger";
//            std::cout << '\n' << "You have found a " << this->name << ". Stab the enemies from behind!" << '\n';
//            this->min_dmg = rand() % 15 + 1;
//            this->max_dmg = min_dmg + 5;
//            SetDurability();
//            break;
//        default:




