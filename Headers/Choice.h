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
    choice(Status &);

    ~choice() = default;

    bool ReturnBuffHygiene() const;

    bool ReturnNerfFun() const;

    void learn_words(Status &y);

    void rat_story(Status &y);

    void baby_story(Status &y) const;
};

#endif //MAIN_CPP_CHOICE_H
