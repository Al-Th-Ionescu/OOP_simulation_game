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
    explicit Player();

    ~Player();

    void ShowPlayer();

    int Difficulty() const;

    unsigned int ReturnAge() const;

    void Death();

    int Luck() const;

    void Aging();

    bool IsDead() const;

};

#endif //MAIN_CPP_PLAYER_H
