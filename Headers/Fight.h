#ifndef MAIN_CPP_FIGHT_H
#define MAIN_CPP_FIGHT_H

#include <iostream>
#include <string>
#include "Opponent.h"
#include "Weapons.h"
#include "Player.h"
#include "Status.h"

class fight {
    unsigned int round;
    opponent y;
public:
    fight();

    ~fight() = default;

    void Attack(Status, weapon &);
};

#endif //MAIN_CPP_FIGHT_H
