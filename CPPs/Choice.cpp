#include <iostream>
#include <string>
#include "../Headers/Choice.h"

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
            baby_story(x, y);

        }
        if (randomize % 3 == 1){
            rat_story(x, y);

        }
        if (randomize %3 == 2){
            learn_words(x, y);
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

void choice::baby_story(Player &x, Status &y) const {
    std::cout << '\n' << "Your mother cannot breastfeed you no more. Should you try the baby formula? [y/n]"
              << '\n';
    char option;
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

void choice::rat_story(Player &x, Status &y) {
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
                  << "Your mother kills the rat. What an unpleasant view! She teaches you how to wash your hands properly."
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

void choice::learn_words(Player &x, Status &y) {
    std::cout << '\n'
              << "Your mother is trying to teach you how to speak! Frustrated because you can't repeat after her, "
                 "she says a swear world. Would you repeat the bad word? [y/n]" << '\n';
    std::cin >> option;
    if (option == 'y' ) {
        std::cout << '\n'
                  << "She starts screaming at you. You start to cry. Trauma starts during childhood: every year "
                     "your fun will decrease by 5";
        nerf_fun = true;
        y . PermanentNerfFun();
        if (buff_hygiene)
            y . PermanentBuffHygiene();
        y . showStats(x);
    }
    if (option == 'n' ) {
        std::cout << '\n'
                  << "Seeing her sad makes you feel bad so you try harder to say a world. You succeed and she "
                     "gives you a candy. Health -2, Fun +20 ";
        if ( y . ReturnFun() <= 20 )
            y . ChangeStats(- 2, 0, 20, 0);
        else
            y . ChangeStats(- 2, 0, 100 - y . ReturnFun(), 0);
        if (buff_hygiene)
            y . PermanentBuffHygiene();
        y . showStats(x);
    }
    x.Aging();
    std::cout<<'\n' << "~~~~~YEAR "<< x.showAge() <<"~~~~~";
}
