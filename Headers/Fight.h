#ifndef MAIN_CPP_FIGHT_H
#define MAIN_CPP_FIGHT_H
#include <iostream>
#include <string>
#include "Opponent.h"
#include "Weapons.h"
#include "Player.h"
#include "Status.h"

class fight{
    unsigned int round;
    weapons x;
    opponent y;
public:
    fight();
    ~fight() = default;
    void Attack(Status);
};

#endif //MAIN_CPP_FIGHT_H
