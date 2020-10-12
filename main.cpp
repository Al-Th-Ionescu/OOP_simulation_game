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
};

Player::Player(std::string name)
{
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
    int health{};
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
    void Died(Player) const;
    void HealthLuck(const Player&);
    void ChangeStats(int, int, int, int);
};


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
    Status::HealthLuck(x);
    if (x.showAge() == 0)
    { std::cout << '\n' << "Your initial stats are:" << '\n' << "Health: " << health << "\n" << "Hygiene: " << hygiene
                  << '\n' << "Fun: " << fun << '\n' << "Wealth: " << Status::ReturnWealth(x) << "$" << '\n';
        Status::Died(x);}
    else {
        std::cout << '\n' << "Your stats are: " << '\n' << "Health: " << health << "\n" << "Hygiene: " << hygiene
                  << '\n' << "Fun: " << fun << '\n' << "Wealth: " << Status::ReturnWealth(x) << "$" << '\n';
        Status::Died(x);
    }
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

choice::choice(int randomize,char option,Player x,Status y)
{

    if(x.showAge()<=2) {
        if (randomize % 10 == 0) {
            std::cout << '\n' << "Your mother cannot breastfeed you no more. Should you try the baby formula? y/n";
            std::cin>> option;
            if (option =='y')
            {
                std::cout<< '\n'<<" You got an allergic reaction and vomited all night long. Health - 10, Hygiene - 25, Fun - 15.";
                y.ChangeStats(-10,-25,-15,0);
                if (x.Luck() ==0 )
                {
                    std::cout<< '\n' <<" You don't have enough money for the formula. Health -5, Fun -20.";
                    y.ChangeStats(-5, 0 , -20 , 0);
                }
            }
            if (option =='n') {
                std::cout << '\n' << " Cow milk was a good substituent for human milk.";
                if (x.Luck() == 0) {
                    std::cout << '\n' << "Too bad you don't have enough money to buy cow milk. Health -5, Fun -20.";
                    y.ChangeStats(-5,0,-20,0);
                }
            }
        }
        if (randomize % 10 ==1 )
            std::cout<< '\n' << " d";
    }
}

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
