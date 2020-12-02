#ifndef MAIN_CPP_CHOICE_H
#define MAIN_CPP_CHOICE_H

#include <iostream>
#include <string>
#include "Status.h"
#include "Player.h"

class choice {
    bool buff_hygiene = false;
    bool nerf_fun = false;

public:
    choice(Player &, Status &);

    ~choice() = default;

    bool ReturnBuffHygiene() const;

    bool ReturnNerfFun() const;

    void Age3(Player &, Status &);

    void Age13(Player &, Status &) const;

    void cat_story(Player &, Status &) const;

    void learn_words(Player &, Status &);

    void rat_story(Player &, Status &);

    void helping_friend(Player &, Status &) const;

    void baby_story(Player &, Status &) const;


};

#endif //MAIN_CPP_CHOICE_H
