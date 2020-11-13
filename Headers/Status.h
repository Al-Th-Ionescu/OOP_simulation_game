#ifndef MAIN_CPP_STATUS_H
#define MAIN_CPP_STATUS_H

#include <iostream>
#include <string>
#include "Player.h"

class Status {
    int health{};
    int hygiene = 100;
    int fun = 100;
    int wealth;

public:

    void SetWealth(Player &);

    void showStats(Player);

    void Died(Player) const;

    void HealthLuck(const Player &);

    void ChangeStats(int, int, int, int);

    int ReturnHealth() const;

    int ReturnWealth() const;

    int ReturnFun() const;

    void PermanentBuffHygiene();

    void PermanentNerfFun();

    void LoseHealth(int);
};

#endif //MAIN_CPP_STATUS_H
