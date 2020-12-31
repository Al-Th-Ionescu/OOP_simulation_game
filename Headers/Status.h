#ifndef MAIN_CPP_STATUS_H
#define MAIN_CPP_STATUS_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Weapons.h"

class Status {
    int health{};
    int hygiene = 100;
    int fun = 100;
    int wealth;
    unsigned int years = 0;
public:

    void SetWealth(Player &);

    void ShowInitStats(Player &);

    void Died(Player &) const;

    void HealthLuck(Player &);

    void ChangeStats(int, int, int, int);

    int ReturnHealth() const;

    int ReturnWealth() const;

    int ReturnFun() const;

    void PermanentBuffHygiene();

    void PermanentNerfFun();

    void LoseHealth(int);

    int ReturnHygiene() const;

    void GetAge(Player &);

    unsigned int ReturnYears() const;

    friend std::ostream &operator<<(std::ostream &, Status &);
};

#endif //MAIN_CPP_STATUS_H
