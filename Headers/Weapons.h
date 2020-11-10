#ifndef MAIN_CPP_WEAPONS_H
#define MAIN_CPP_WEAPONS_H
#include <iostream>
#include <string>

class weapons{
    std::string name;
    int min_dmg;
    int max_dmg;
    int crit_chance;
    int durability=100;
public:

    weapons();
    ~weapons();
    int ReturnDmg() const;
    void Use();
    int ReturnDur() const;
    std::string ReturnWeap();
};


#endif //MAIN_CPP_WEAPONS_H
