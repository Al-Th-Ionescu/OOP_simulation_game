#include "../Headers/Player.h"



void Player::SetName() {
    std::string PlayerName;
    std::cout<<"Introduce your name: ";
    std::cin>>PlayerName;
    this->name=PlayerName;
}

int Player::Difficulty() const {
    if (luck % 3 == 0)
        return 0;
    if (luck % 3 == 1)
        return 1;
    return 2;
}

unsigned int Player::ReturnAge() const {
    return age;
}


int Player::Luck() const {
    return luck;
}

void Player::Death() {
    dead = true;
}

void Player::ShowPlayer() {
    {
        std::cout << '\n' << "Your character was created successfully!" << '\n' << " Your name is " << GetName() << "."
                  << '\n';
        srand(time(nullptr));
        luck = rand();
        if (Player::Difficulty() == 0)
            std::cout << " You are a poor child born in Syria."; //Hardest difficulty
        else if (Player::Difficulty() == 1)
            std::cout << " You were born in a modest family from Ukraine."; //Moderate difficulty
        else
            std::cout
                    << " What a luxury! You were born in Sweden and you are a part of the royal family!"; //Easy difficulty
    }
}

void Player::Aging() {
    age++;
}

bool Player::IsDead() const {
    return dead;
}

std::string Player::GetName() {
    if (name.empty())
        SetName();
    return name;
}

Player* Player::play= nullptr;
