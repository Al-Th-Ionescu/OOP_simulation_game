#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include <iostream>
#include <string>
#include <time.h>

class Player {

    std::string name;
    int luck{};
    unsigned int age = 0;
    bool dead = false;
public:
    explicit Player(std::string name);

    ~Player();

    void showPlayer();

    int Difficulty() const;

    unsigned int showAge() const;

    void Death();

    int Luck() const;

    void Aging();
};

#endif //MAIN_CPP_PLAYER_H
