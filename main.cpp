#include <iostream>
#include <string>
#include <time.h>

class Player{

    std::string name;
    int luck{};
    unsigned int age=0;
    bool dead=false;
public:
    explicit Player(std::string name);
    ~Player();

    void showPlayer();
    int Difficulty() const;
    unsigned int showAge();
    void Death();
    int Luck() const;
    void Aging();
};

Player::Player(std::string name){
    std::cout << "Introduce your name: ";
    std::cin >>name;
    this->name=name;
}

Player::~Player() {
    if (dead == true )
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

int Player::Luck() const {
    return luck;
}
void Player::Death() {
    dead = true;
}

void Player::showPlayer() {
    {
        std::cout <<'\n' << "Your character was created successfully!"<<'\n' << " Your name is "<<name<<"." << '\n';
        srand(time(nullptr));
        luck = rand();
        if (Player::Difficulty() == 0)
            std::cout << " You are a poor child born in Syria."; //Hardest difficulty
        else
        if (Player::Difficulty() == 1)
            std::cout << " You were born in a modest family from Ukraine."; //Moderate difficulty
        else
            std::cout<< " What a luxury! You were born in Sweden and you are a part of the royal family!"; //Easy difficulty
    }
}

void Player::Aging() {
    age++;
}

class Status {
    int health{};
    int hygiene=100;
    int fun=100;
    int wealth=100;
public:

    void SetWealth(Player &x)
    {
        if (x.Difficulty() == 0 )
            wealth = 3;
        else if (x.Difficulty() == 1)
            wealth = 300;
        else
            wealth = 30000;
    }
    void showStats(Player);
    void Died(Player) const;
    void HealthLuck(const Player&);
    void ChangeStats(int, int, int, int);
    int ReturnHealth();
    int ReturnWealth();

};

int Status::ReturnWealth()
{
    return wealth;
}

void Status::HealthLuck(const Player& x) {
    if (x.Luck() % 7 < 3 ) {
        std::cout
                << '\n' << " You were born with a bad malformation. There will be surgeries needed in order to fix your health." << '\n' ;
        health = 40;
    }
    if (x.Luck() % 7 >= 3 && x.Luck() % 7 < 5)
    {
        std :: cout << '\n' << " You were born with some lung problems. Nothing to worry about but you'll need to pay for a treatment."<< '\n';
        health = 75;
    }
    if (x.Luck() % 7 >= 5)
    {
        std::cout << '\n' << "You were born perfectly healthy."<< '\n' ;
        health=100;
    }
}
void Status::showStats(Player x) {

    if (x.showAge() == 0){
        Status::HealthLuck(x);
        Status::SetWealth(x);
        std::cout << '\n' << "Your initial stats are:" << '\n' << "Health: " << health << "\n" << "Hygiene: " << hygiene
                << '\n' << "Fun: " << fun << '\n' << "Wealth: " << Status::ReturnWealth() << "$" << '\n';

    }
    else {
        std::cout << '\n' << "Your stats are: " << '\n' << "Health: " << health << "\n" << "Hygiene: " << hygiene
                  << '\n' << "Fun: " << fun << '\n' << "Wealth: " << Status::ReturnWealth() << "$" << '\n'<<"Age: "<<x.showAge();
        Status::Died(x);
    }
}

int Status::ReturnHealth() {
    return health;
}

void Status::Died(Player x) const {
    if (health <= 0 || hygiene <= 0 || fun <= 0)
        x.Death();
}

void Status::ChangeStats(int x, int y, int z, int t) {
    health= health + x;
    hygiene= hygiene + y;
    fun = fun + z;
    wealth = wealth + t;
}

class choice{
    int randomize;
    char option;

public:
    choice(int,char,Player,Status);
    ~choice();
};

choice::choice(int randomize,char option,Player x,Status y) {
    if (x.Luck() % 7 < 5) {
        std::cout << '\n' << " Do you want to fix your health issues? [y/n]" << '\n';
        if (y.ReturnHealth() == 40)
            std::cout << "It will cost 250$" << '\n';
        else
            std::cout << " It will cost 50$" << '\n';
        std::cin >> option;
        if (option == 'y' &&
            ((y.ReturnHealth() == 40 && y.ReturnWealth() < 250) || (y.ReturnHealth() == 75 && y.ReturnWealth() < 50)))
            std::cout << '\n' << "You don't have enough money!" << '\n';
        else if (option == 'n')
            std::cout << '\n' << "Your health remains the same!" << '\n';
        else {
            if (y.ReturnHealth() == 40)
                y.ChangeStats(60, 0, 0, -250);
            else
                y.ChangeStats(25, 0, 0, -50);
            std::cout << "Your health got back to the maximum (100)!" << '\n';
        }

    }
    x.Aging();
    std::cout<<'\n' << "~~~~~YEAR "<< x.showAge() <<"~~~~~";
    if (x.showAge() <= 2) {
        if (randomize % 10 == 0) {
            std::cout << '\n' << "Your mother cannot breastfeed you no more. Should you try the baby formula? [y/n]"
                      << '\n';
            std::cin >> option;
            if (option == 'y') {
                if (x.Difficulty() != 0) {
                    std::cout << '\n'
                              << " You got an allergic reaction and vomited all night long. Health - 10, Hygiene - 25, Fun - 15.";
                    y.ChangeStats(-10, -25, -15, 0);
                    y.showStats(x);
                } else {
                    std::cout << '\n' << " You don't have enough money for the formula. Health -5, Fun -20.";
                    y.ChangeStats(-5, 0, -20, 0);
                    y.showStats(x);
                }
            }
            if (option == 'n') {
                if (x.Difficulty() != 0){
                    std::cout << '\n' << " Cow milk was a good substituent for human milk.";
                    y.showStats(x);
                }
                else {
                    std::cout << '\n' << "Too bad you don't have enough money to buy cow milk. Health -5, Fun -20.";
                    y.ChangeStats(-5, 0, -20, 0);
                    y.showStats(x);
                }
            }
        }
        if (randomize % 10 == 1)
            std::cout << '\n' << " d";
    }
}
choice::~choice() {}

int main() {
    std::string name;
    char opt;
    Player x(name);
    Status y;
    x.showPlayer();
    y.showStats(x);
    choice z(0,opt,x,y);
    return 0;
}