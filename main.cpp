#include <iostream>
#include <string>
#include <time.h>

class Player{

    std::string name;
    int luck;
    unsigned int age=0;
    bool dead=false;
public:
    Player(std::string name);
    ~Player();

    void showPlayer();
    int Difficulty() const;
    unsigned int showAge();
    void Death();
};

Player::Player(std::string name)
{
    std::cout << "Introduce your name: ";
    std::cin >>name;
    this->name=name;
}

Player::~Player() {
    if (dead)
    std::cout << '\n' << name << " has died.";
    }

int Player::Difficulty() const {
    if (luck % 3 ==0 )
        return 0;
    if (luck %3 == 1)
        return 1;
    return 2;
}


 unsigned int Player::showAge()  {
    return age;
}

void Player::Death() {
    dead = true;
}

void Player::showPlayer() {
    {
        std::cout <<'\n' << "Your character was created successfully!"<<'\n' << " Your name is "<<name<<"." << '\n';
        srand(time(nullptr));
        luck = rand();
        if (Player::Difficulty() ==0)
            std::cout << " You are a poor child born in Syria."; //Hardest level
        else
        if (Player::Difficulty() == 1)
            std::cout << " You were born in a modest family from Ukraine."; //Moderate difficulty
        else
            std::cout<< " What a luxury! You were born in Sweden and you are a part of the royal family!"; //Easy difficulty
    }
}

class Status {
    int health=100;
    int hygiene=100;
    int fun=100;
    int wealth=100;
public:

    int ReturnWealth(Player &x)
    {
        if (x.Difficulty() == 0 )
            wealth = 3;
        else if (x.Difficulty() == 1)
            wealth = 300;
        else
            wealth = 30000;
        return wealth;
    }
    void showStats(Player);
    bool Died(Player);
};

void Status::showStats(Player x) {
    if (x.showAge() == 0)
        std::cout << '\n' << "Your initial stats are:" << '\n' <<"Health: " << health << "\n" <<"Hygiene: "<< hygiene << '\n' << "Fun: " << fun << '\n' <<"Wealth: " << Status::ReturnWealth(x) <<  "$" << '\n';
    else
        std::cout << '\n' << "Your stats are: "<< '\n' <<"Health: " << health << "\n" <<"Hygiene: "<< hygiene << '\n' << "Fun: " << fun << '\n' <<"Wealth: " << Status::ReturnWealth(x) << "$" <<'\n';
}

bool Status::Died(Player x) {
    if (health <= 0 || hygiene <= 0 || fun <= 0)
        x.Death();
}

int main() {
    std::string name;
    Player x(name);
    Status y;
    x.showPlayer();
    y.showStats(x);
    return 0;
}
