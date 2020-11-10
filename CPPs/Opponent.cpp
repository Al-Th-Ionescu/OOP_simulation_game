#include <iostream>
#include <string>
#include "../Headers/Opponent.h"

opponent::opponent() {
    int random = rand() % 10;
    switch (random) {
        case 0:
            this -> enemy = "Tarantula";
            this -> enemy_life = 30;
            this -> enemy_dmg = 5;
            break;

        case 1:
            this -> enemy = "Wolf";
            this -> enemy_life = 45;
            this -> enemy_dmg = 10;
            break;

        case 2:
            this -> enemy = "Bear";
            this -> enemy_life = 75;
            this -> enemy_dmg = 25;
            break;

        case 3:
            this -> enemy = "Boar";
            this -> enemy_life = 35;
            this -> enemy_dmg = 7;
            break;

        case 4:
            this -> enemy = "Thief";
            this -> enemy_life = 60;
            this -> enemy_dmg = 12;
            break;

        case 5:
            this -> enemy = "Witch";
            this -> enemy_life = 25;
            this -> enemy_dmg = 45;
            break;

        case 6:
            this -> enemy = "Bat";
            this -> enemy_life = 10;
            this -> enemy_dmg = 5;
            break;

        case 7:
            this -> enemy = "Snake";
            this -> enemy_life = 34;
            this -> enemy_dmg = 15;
            break;

        case 8:
            this -> enemy = "Demon";
            this -> enemy_life = 105;
            this -> enemy_dmg = 2;
            break;

        case 9:
            this -> enemy = "Crocodile";
            this -> enemy_life = 60;
            this -> enemy_dmg = 20;
            break;
        default:
            break;

    }
    std::cout << '\n' << "A " << this -> enemy << " has appeared. The enemy has: " << this -> enemy_life
              << " health points" << '\n';
}

opponent::~opponent()=default;

std::string opponent::ReturnName() {
    return enemy;
}

void opponent::TakeDmg(int x) {
    enemy_life = enemy_life - x;
    if ( enemy_life <= 0 )
        std::cout << '\n' << enemy << " has died." << '\n';
}

int opponent::ReturnEnemyHealth() const {
    return enemy_life;
}

int opponent::ReturnEnemyDmg() const {
    return enemy_dmg;
}

