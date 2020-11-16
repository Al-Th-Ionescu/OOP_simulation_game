#ifndef MAIN_CPP_STATUS_H
#define MAIN_CPP_STATUS_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Weapons.h"

class Status : public Player {
    int health{};
    int hygiene = 100;
    int fun = 100;
    int wealth;

public:

    void SetWealth();

    void ShowInitStats();

    void Died();

    void HealthLuck();

    void ChangeStats(int, int, int, int);

    int ReturnHealth() const;

    int ReturnWealth() const;

    int ReturnFun() const;

    void PermanentBuffHygiene();

    void PermanentNerfFun();

    void LoseHealth(int);

    int ReturnHygiene() const;


    friend std::ostream &operator<<(std::ostream &, Status &);
};

#endif //MAIN_CPP_STATUS_H
