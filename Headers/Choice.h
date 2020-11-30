#ifndef MAIN_CPP_CHOICE_H
#define MAIN_CPP_CHOICE_H

#include <iostream>
#include <string>
#include "Status.h"
#include "Player.h"

class choice {
    char option;
    bool buff_hygiene = false;
    bool nerf_fun = false;

public:
    choice(Status &);

    ~choice() = default;

    bool ReturnBuffHygiene() const;

    bool ReturnNerfFun() const;

    void Age3(Status &);

    void Age13(Status &);

    void cat_story(Status &);

    void learn_words(Status &);

    void rat_story(Status &);

    void helping_friend(Status &);

    void baby_story(Status &) const;


};

#endif //MAIN_CPP_CHOICE_H
