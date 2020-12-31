#ifndef MAIN_CPP_WEAPONS_H
#define MAIN_CPP_WEAPONS_H

#include <iostream>
#include <string>

class weapon {
    int durability=100;
public:

    weapon();

    virtual ~weapon() =0;

    virtual void Use();

    virtual int GetDurability();

    virtual void ShowDurability();

    virtual int ReturnDmg()=0;

    virtual std::string ReturnWeap()=0;

    virtual void init();

    virtual void BreakWeapon();

    virtual int ReturnMinDmg()=0;

    virtual void ShowRemain();

    virtual void UseNotBroken();


};


#endif //MAIN_CPP_WEAPONS_H
