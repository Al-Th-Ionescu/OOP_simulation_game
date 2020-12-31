#include <iostream>
#include <string>
#include "../Headers/Choice.h"

void choice::VerifDead(Player &p) {
    if (p.IsDead())
        throw (std::runtime_error("DEAD"));
}

choice::choice(Player &p, Status &y) {
    char option;
    if (p.Luck() % 7 < 5) {
        std::cout << '\n' << " Do you want to fix your health issues? [y/n]" << '\n';
        if (y.ReturnHealth() == 40)
            std::cout << "It will cost 250$" << '\n';
        else
            std::cout << " It will cost 50$" << '\n';
        std::cin >> option;
        if (tolower(option) != 'y' && tolower(option) != 'n') {
            option = 'n';
            std::cout << '\n' << "You selected the wrong option so by default your option will be 'no'!" << '\n';
        }
        if (tolower(option) == 'y' &&
            ((y.ReturnHealth() == 40 && y.ReturnWealth() < 250) || (y.ReturnHealth() == 75 && y.ReturnWealth() < 50)))
            std::cout << '\n' << "You don't have enough money!" << '\n';
        else if (tolower(option) == 'n')
            std::cout << '\n' << "Your health remains the same!" << '\n';
        else {
            if (y.ReturnHealth() == 40)
                y.ChangeStats(60, 0, 0, -250);
            else
                y.ChangeStats(25, 0, 0, -50);
            std::cout << "Your health got back to the maximum (100)!" << '\n';
        }

    }
    y.GetAge(p);
    p.Aging();
}

void choice::Age3(Player &p, Status &y) {
    std::cout << '\n' << "~~~~~YEAR " << p.ReturnAge() << "~~~~~";
    int randomize = rand();
    while (p.ReturnAge() <= 2) {
        int aux = randomize % 3;
        if (randomize % 3 == 0) {
            baby_story(p, y);
            std::cout << '\n' << "~~~~~YEAR " << p.ReturnAge() << "~~~~~";

        }
        if (randomize % 3 == 1) {
            rat_story(p, y);
            std::cout << '\n' << "~~~~~YEAR " << p.ReturnAge() << "~~~~~";

        }
        if (randomize % 3 == 2) {
            learn_words(p, y);
            std::cout << '\n' << "~~~~~YEAR " << p.ReturnAge() << "~~~~~";
        }
        while (aux == randomize % 3)
            randomize = rand();
    }
}

void choice::Nerf(Status &s) const {
    if (nerf_fun)
        s.PermanentNerfFun();
}

void choice::Buff(Status &s) const {
    if (buff_hygiene)
        s.PermanentBuffHygiene();
}

void choice::baby_story_result_yes(Player &p, Status &y) const {
    if (p.Difficulty() != 0) {
        std::cout << '\n'
                  << " You got an allergic reaction and vomited all night long. Health - 10, Hygiene - 25, Fun - 15.";
        y.ChangeStats(-10, -25, -15, 0);
        Buff(y);
        Nerf(y);
    } else {
        std::cout << '\n' << " You don't have enough money for the formula. Health -5, Fun -20.";
        y.ChangeStats(-5, 0, -20, 0);
        Buff(y);
        Nerf(y);
    }
}

void choice::baby_story_result_no(Player &p, Status &s) const {
    if (p.Difficulty() != 0) {
        std::cout << '\n' << " Cow milk was a good substituent for human milk.";
        Buff(s);
        Nerf(s);
    } else {
        std::cout << '\n' << "Too bad you don't have enough money to buy cow milk. Health -5, Fun -20.";
        s.ChangeStats(-5, 0, -20, 0);
        Buff(s);
        Nerf(s);
    }
}

void choice::baby_story(Player &p, Status &y) const {
    std::cout << '\n' << "Your mother cannot breastfeed you no more. Should you try the baby formula? [y/n]"
              << '\n';
    char option;
    std::cin >> option;
    if (tolower(option) != 'y' && tolower(option) != 'n') {
        option = 'y';
        std::cout << '\n' << "You haven't selected a valid option so by default the option will be yes!" << '\n';
    }
    if (tolower(option) == 'y')
        baby_story_result_yes(p, y);
    if (tolower(option) == 'n') {
        baby_story_result_no(p, y);
    }
    y.GetAge(p);
    std::cout << '\n' << y;
    y.Died(p);
    p.Aging();
    VerifDead(p);
}

void choice::rat_story_result_1(Player &p, Status &s) const {
    std::cout << '\n'
              << "It turns out the rat is friendly and did not bite you. Too bad you got fleas infested. Hygiene -5 , Fun +10"
              << '\n';
    if (s.ReturnFun() <= 90)
        s.ChangeStats(0, -5, 10, 0);
    else
        s.ChangeStats(0, -5, 100 - s.ReturnFun(), 0);
    Nerf(s);
}

void choice::rat_story_result_2(Player &p, Status &s) {
    std::cout << '\n'
              << "Your mother kills the rat. What an unpleasant view! She teaches you how to wash your hands properly."
                 "Your fun decreases by 5, but every year you'll gain +3 hygiene." << '\n';
    s.ChangeStats(0, 0, -5, 0);
    buff_hygiene = true;
    Buff(s);
    Nerf(s);
}

void choice::rat_story(Player &p, Status &y) {
    std::cout << '\n' << "From a hole a rat emerged. What will you do? " << '\n' << "1) Pet the rat."
              << '\n' << "2)Cry for help" << '\n';
    char option;
    std::cin >> option;
    if (option != '1' && option != '2') {
        option = '1';
        std::cout << '\n' << "You haven't selected a valid option so by default the option will be 1!" << '\n';
    }
    if (option == '1')
        rat_story_result_1(p, y);
    if (option == '2')
        rat_story_result_2(p, y);
    y.GetAge(p);
    std::cout << '\n' << y;
    y.Died(p);
    p.Aging();
    VerifDead(p);
}

void choice::learn_words_result_yes(Player &p, Status &s) {
    std::cout << '\n'
              << "She starts screaming at you. You start to cry. Trauma starts during childhood: every year "
                 "your fun will decrease by 5";
    nerf_fun = true;
    s.PermanentNerfFun();
    Buff(s);
}

void choice::learn_words_result_no(Player &p, Status &s) const {
    std::cout << '\n'
              << "Seeing her sad makes you feel bad so you try harder to say a world. You succeed and she "
                 "gives you a candy. Health -2, Fun +20 ";
    if (s.ReturnFun() <= 20)
        s.ChangeStats(-2, 0, 20, 0);
    else
        s.ChangeStats(-2, 0, 100 - s.ReturnFun(), 0);
    Buff(s);
}

void choice::learn_words(Player &p, Status &y) {
    std::cout << '\n'
              << "Your mother is trying to teach you how to speak! Frustrated because you can't repeat after her, "
                 "she says a swear world. Would you repeat the bad word? [y/n]" << '\n';
    char option;
    std::cin >> option;
    if (tolower(option) != 'y' && tolower(option) != 'n') {
        option = 'y';
        std::cout << '\n' << "You haven't selected a valid option so by default the option will be yes!" << '\n';
    }
    if (tolower(option) == 'y')
        learn_words_result_yes(p, y);
    if (tolower(option) == 'n')
        learn_words_result_no(p, y);
    y.GetAge(p);
    std::cout << '\n' << y;
    y.Died(p);
    p.Aging();
    VerifDead(p);
}

void choice::cat_story_result_yes(Player &p, Status &s) {
    std::cout << '\n' << "Your parents are mad because you did not ask for permission first."
                         " Also the cat pooped on your mother's rug! Hygiene -5 , Fun +20" << '\n';
    if (s.ReturnFun() > 20)
        s.ChangeStats(0, -5, 100 - s.ReturnFun(), 0);
    else
        s.ChangeStats(0, -5, 20, 0);
}

void choice::cat_story_result_no(Player &p, Status &s) {
    std::cout << '\n' << "You are sad leaving the kitten behind. You go home crying. "
                         "The next day you pass the place where you've seen the kitten and see its dead body."
                         "The feeling of guilt makes you feel miserable. Fun -30";
    s.ChangeStats(0, 0, -30, 0);
}

void choice::cat_story(Player &p, Status &y) const {
    std::cout << '\n' << "Wandering in your garden you hear a soft sound. "
                         "You follow the noise and found a small baby kitten. "
                         "Should you pick it up and bring it home? [y/n]" << '\n';
    char option;
    std::cin >> option;
    if (tolower(option) != 'y' && tolower(option) != 'n') {
        option = 'y';
        std::cout << '\n' << "You haven't selected a valid option so by default the option will be yes!" << '\n';
    }
    if (tolower(option) == 'y')
        cat_story_result_yes(p, y);
    if (tolower(option) == 'n')
        cat_story_result_no(p, y);
    Nerf(y);
    Buff(y);
    y.GetAge(p);
    std::cout << '\n' << y;
    y.Died(p);
    p.Aging();
    VerifDead(p);
}

void choice::helping_friend_result_1(Player &p, Status &s) {
    std::cout << "You had a great time together! She spoke about how her mother taught her the importance "
                 "of avoiding getting sick by not eating food that has been dropped on the ground! "
                 "You won't do that from now on. Health +5, Hygiene +15" << '\n';
    if (s.ReturnHealth() > 95)
        s.ChangeStats(100 - s.ReturnHealth(), 0, 0, 0);
    else
        s.ChangeStats(5, 0, 0, 0);
    if (s.ReturnHygiene() > 85)
        s.ChangeStats(0, 100 - s.ReturnHygiene(), 0, 0);
    else
        s.ChangeStats(0, 15, 0, 0);
}

void choice::helping_friend_result_2(Player &p, Status &s) {
    std::cout << '\n' << "You had a great time together! Daniel showed you his toys and you played"
                         "for hours! Life is not that bad when you have a friend to spend your time with!"
                         "Fun +30" << '\n';
    if (s.ReturnFun() > 70)
        s.ChangeStats(0, 0, 100 - s.ReturnFun(), 0);
    else
        s.ChangeStats(0, 0, 30, 0);
}

void choice::helping_friend_result_3(Player &p, Status &s) {
    std::cout << '\n' << "What a boring day! You did nothing at all and wasted an important day of your life."
                         "Fun -10";
    s.ChangeStats(0, 0, -10, 0);
}

void choice::helping_friend(Player &p, Status &y) const {
    std::cout << "\n" << "Your friends Sophia and Daniel invited you over to play. Who do you choose to visit?" << '\n'
              <<
              "1- Sophia ~~~~~~~~~  2- Daniel ~~~~~~~~~  3- none ~~~~~~~~~" << '\n';
    char option;
    std::cin >> option;
    if (option != '1' && (option != '2' && option != '3')) {
        option = '3';
        std::cout << '\n' << "You haven't selected a valid option so by default the option will be 3!" << '\n';
    }
    if (option == '1')
        helping_friend_result_1(p, y);
    if (option == '2')
        helping_friend_result_2(p, y);
    if (option == '3')
        helping_friend_result_3(p, y);
    Buff(y);
    Nerf(y);
    y.GetAge(p);
    std::cout << '\n' << y;
    y.Died(p);
    p.Aging();
    VerifDead(p);
}

void choice::Age13(Player &p, Status &y) const {
    cat_story(p, y);
    std::cout << '\n' << "~~~~~YEAR " << p.ReturnAge() << "~~~~~" << '\n';
    helping_friend(p, y);
    std::cout << '\n' << "~~~~~YEAR " << p.ReturnAge() << "~~~~~" << '\n';
}