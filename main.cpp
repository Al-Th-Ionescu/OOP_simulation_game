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
    unsigned int showAge() const;
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
    if (dead)
        std::cout << '\n' << name << " has died at age of "<<showAge()<<".";
}

int Player::Difficulty() const {
    if (luck % 3 ==0 )
        return 0;
    if (luck %3 == 1)
        return 1;
    return 2;
}


unsigned int Player::showAge() const  {
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
    int hygiene = 100;
    int fun = 100;
    int wealth = 100;

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
    int ReturnHealth() const;
    int ReturnWealth() const;
    int ReturnFun() const;
    void PermanentBuffHygiene();
    void PermanentNerfFun();
};

int Status::ReturnWealth() const
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

void Status::PermanentBuffHygiene() {
    if (hygiene<=97)
        hygiene=hygiene+3;
    else
        hygiene= 100;
}

void Status::PermanentNerfFun() {
    fun=fun-5;
}

int Status::ReturnHealth() const {
    return health;
}

int Status::ReturnFun() const {
    return fun;
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

class weapons{
    std::string name;
    unsigned int min_dmg;
    unsigned int max_dmg;
    unsigned int crit_chance;
    unsigned int durability=100;
public:

    weapons(std::string name);
    ~weapons();
    void attack();
};

weapons::weapons(std::string name) {
    if(rand() % 4 ==0 )
    {
        name="stick";
        this->name = name;
        std::cout<< '\n' << "You have found a "<<name<<". Use it wisely."<<'\n';
        min_dmg = rand() % 10 + 1;
        max_dmg = min_dmg + 15;
        std::cout<<'Its dmg is: '<<min_dmg<<"-"<<max_dmg;
    }
    if (rand() % 4 ==1 )
    {
        name="sword";
        this->name = name;
        std::cout<< '\n'<<"You have found a "<<name<<". Careful not to cut yourself!"<<'\n';
        min_dmg = rand() % 25 + 1;
        max_dmg = min_dmg + 10;
        std::cout<<"Sword's dmg is: "<< min_dmg << "-"<<max_dmg;
    }
    if (rand() %4 == 2)
    {
        name="bow";
        this->name = name;
        std::cout<<'\n'<<"You have found a "<<name<<". Make the arrows rain!"<<'\n';
        min_dmg = rand() % 35 + 1;
        max_dmg = min_dmg + 20;
        std::cout<<"The bow's dmg is: "<<min_dmg<<"-"<<max_dmg;
    }
    if (rand() %4 == 3)
    {
        name ="dagger";
        this->name = name;
        std::cout<<'\n'<<"You have found a "<<name<<". Stab the enemies from behind!";
        min_dmg = rand() % 15 +1;
        max_dmg = min_dmg + 5;
        std::cout<<"The dagger's dmg is: "<<min_dmg<<"-"<<max_dmg;
    }
}

weapons::~weapons() {
    if (durability <= 0)
        std::cout<< '\n' << "Look like your weapon broke and vanished into the void." << '\n';
}


class fight{
    std::string enemy;
    unsigned int enemy_life;
    unsigned int enemy_dmg;
public:
    fight(std::string);
    ~fight();
};

fight::fight(std::string name)
{
    if (rand() % 10 == 0)
    {
        name="Tarantula";
        this->enemy = name;
        enemy_life= 30;
        enemy_dmg=5;
        std::cout<<'\n'<< "A " << name <<" has appeared. The enemy has: "<<enemy_life<<" health points.";
    }

    if (rand() % 10 == 1)
    {
        name="Wolf";
        this->enemy = name;
        enemy_life = 45;
        enemy_dmg = 10;
        std::cout << '\n' << "A " << name<<" has appeared. The enemy has: "<<enemy_life<<" health points.";
    }

    if (rand() % 10 == 2)
    {
        name="Bear";
        this->enemy = name;
        enemy_life = 75;
        enemy_dmg = 25;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 ==3)
    {
        name= "Boar";
        this->enemy = name;
        enemy_life = 35;
        enemy_dmg = 7;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 == 4)
    {
        name= "Thief";
        this->enemy = name;
        enemy_life= 60;
        enemy_dmg = 12;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 == 5)
    {
        name = "Witch";
        this->enemy = name;
        enemy_life = 25;
        enemy_dmg = 45;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 == 6)
    {
        name = "Bat";
        this->enemy = name;
        enemy_life = 10;
        enemy_dmg = 5;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 == 7)
    {
        name = "Snake";
        this->enemy = name;
        enemy_life = 34;
        enemy_dmg = 15;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 == 8)
    {
        name = "Demon";
        this->enemy = name;
        enemy_life = 105;
        enemy_dmg = 2;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
    if (rand() % 10 == 9)
    {
        name = "Crocodile";
        this->enemy = name;
        enemy_life = 60;
        enemy_dmg = 20;
        std::cout<< '\n'<< "A "<< name <<" has appeared. The emeny has: "<< enemy_life<<" health points";
    }
}


fight::~fight()
{
    if (enemy_life ==0 )
        std::cout<<'\n'<<enemy<<"has died.";
}
class choice{
    int randomize;
    char option{};
    bool buff_hygiene = false;
    bool nerf_fun = false;

public:
    choice(Player,Status);
    ~choice() = default;
    bool ReturnBuffHygiene();
    bool ReturnNerfFun();
};

bool choice::ReturnBuffHygiene(){
    return buff_hygiene;
}

bool choice::ReturnNerfFun() {
    return nerf_fun;
}

choice::choice(Player x,Status y) {
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
    randomize=rand();
    while (x.showAge() <= 2) {
        int aux= randomize % 3;
        if (randomize % 3 == 0) {
            std::cout << '\n' << "Your mother cannot breastfeed you no more. Should you try the baby formula? [y/n]"
                      << '\n';
            std::cin >> option;
            if (option == 'y') {
                if (x.Difficulty() != 0) {
                    std::cout << '\n'
                              << " You got an allergic reaction and vomited all night long. Health - 10, Hygiene - 25, Fun - 15.";
                    y.ChangeStats(-10, -25, -15, 0);
                    if (buff_hygiene)
                        y.PermanentBuffHygiene();
                    if (nerf_fun)
                        y.PermanentNerfFun();
                    y.showStats(x);
                } else {
                    std::cout << '\n' << " You don't have enough money for the formula. Health -5, Fun -20.";
                    y.ChangeStats(-5, 0, -20, 0);
                    if (buff_hygiene)
                        y.PermanentBuffHygiene();
                    if (nerf_fun)
                        y.PermanentNerfFun();
                    y.showStats(x);
                }
            }
            if (option == 'n') {
                if (x.Difficulty() != 0) {
                    std::cout << '\n' << " Cow milk was a good substituent for human milk.";
                    if (buff_hygiene)
                        y.PermanentBuffHygiene();
                    if (nerf_fun)
                        y.PermanentNerfFun();
                    y.showStats(x);
                } else {
                    std::cout << '\n' << "Too bad you don't have enough money to buy cow milk. Health -5, Fun -20.";
                    y.ChangeStats(-5, 0, -20, 0);
                    if (buff_hygiene)
                        y.PermanentBuffHygiene();
                    if (nerf_fun)
                        y.PermanentNerfFun();
                    y.showStats(x);
                }
            }
            x.Aging();
            std::cout<<'\n' << "~~~~~YEAR "<< x.showAge() <<"~~~~~";

        }
        if (randomize % 3 == 1){
            std::cout << '\n' << "From a hole a rat emerged. What will you do? " << '\n' << "1) Pet the rat."
                      << '\n' << "2)Cry for help" << '\n';
        std::cin >> option;
        if (option == '1') {
            std::cout << '\n'
                      << "It turns out the rat is friendly and did not bite you. Too bad you got fleas infested. Hygiene -5 , Fun +10"
                      << '\n';
            if (y.ReturnFun() <= 90)
                y.ChangeStats(0, -5, 10, 0);
            else
                y.ChangeStats(0, -5, 100 - y.ReturnFun(), 0);
            if (nerf_fun)
                y.PermanentNerfFun();
            y.showStats(x);
        }
        if (option == '2') {
            std::cout << '\n'
                      << "Your mother kills the rat. What an unpleasant view! She teaches you to wash your hands."
                         "Your fun decreases by 5, but every year you'll gain +3 hygiene." << '\n';
            y.ChangeStats(0, 0, -5, 0);
            buff_hygiene = true;
            y.PermanentBuffHygiene();
            if (nerf_fun)
                y.PermanentNerfFun();
            y.showStats(x);
        }
        x.Aging();
        std::cout<<'\n' << "~~~~~YEAR "<< x.showAge() <<"~~~~~";

    }
        if (randomize %3 == 2){
            std::cout<< '\n' <<"Your mother is trying to teach you how to speak! Frustrated because you can't repeat after her, "
                               "she says a swear world. Would you repeat the bad word? [y/n]" << '\n';
            std::cin>>option;
            if (option == 'y')
            {
                std::cout<< '\n' << "She starts screaming at you. You start to cry. Trauma starts during childhood: every year "
                                    "your fun will decrease by 5";
                nerf_fun = true;
                y.PermanentNerfFun();
                if (buff_hygiene)
                    y.PermanentBuffHygiene();
                y.showStats(x);
            }
            if (option =='n')
            {
                std::cout<< '\n' <<"Seeing her sad makes you feel bad so you try harder to say a world. You succeed and she "
                                   "gives you a candy. Health -2, Fun +20 ";
                if (y.ReturnFun()<=20)
                    y.ChangeStats(-2,0,20,0);
                else
                    y.ChangeStats(-2, 0 , 100-y.ReturnFun(),0);
                if (buff_hygiene)
                    y.PermanentBuffHygiene();
                y.showStats(x);
            }
            x.Aging();
            std::cout<<'\n' << "~~~~~YEAR "<< x.showAge() <<"~~~~~";
        }
        while (aux == randomize %3 )
            randomize=rand();
    }

   /* while (x.showAge() <= 10 && x.showAge() >2 ){
        if (randomize % 10 ==0)
        {
            std::cout<< '\n' << " ";
        }
    }*/
}


int main() {
    std::string name;
    Player x(name);
    Status y;
    x.showPlayer();
    y.showStats(x);
    choice(x,y);
    return 0;
}