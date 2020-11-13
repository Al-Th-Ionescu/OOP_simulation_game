#ifndef MAIN_CPP_CHOICE_H
#define MAIN_CPP_CHOICE_H

#include <iostream>
#include <string>
#include "Status.h"
#include "Player.h"

class choice {
    int randomize;
    char option;
    bool buff_hygiene = false;
    bool nerf_fun = false;

public:
    choice(Player, Status);

    ~choice() = default;

    bool ReturnBuffHygiene();

    bool ReturnNerfFun();

    void learn_words(Player &x, Status &y);

    void rat_story(Player &x, Status &y);

    void baby_story(Player &x, Status &y) const;
};

#endif //MAIN_CPP_CHOICE_H
