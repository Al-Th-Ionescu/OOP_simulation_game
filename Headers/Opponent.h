#ifndef MAIN_CPP_OPPONENT_H
#define MAIN_CPP_OPPONENT_H

#include <iostream>
#include <string>

class opponent {
    std::string enemy;
    int enemy_life;
    int enemy_dmg;
public:
    opponent();

    ~opponent();

    std::string ReturnName();

    void TakeDmg(int);

    int ReturnEnemyHealth() const;

    int ReturnEnemyDmg() const;

    opponent &operator=(const opponent &);

    opponent(opponent &);
};

#endif //MAIN_CPP_OPPONENT_H
