#include <iostream>
#include <string>
#include "../Headers/Fight.h"

fight::fight() {
    round = 1;

}

void fight::YourTurn(Player &p, Status &s, weapon &w, opponent& a) const {
    if (round % 2 == 1) {
        int dmg = w.ReturnDmg();
        std::cout << "You have attacked the " << a.ReturnName() << " and dealt " << dmg << " dmg." << '\n';
        w.UseNotBroken();
        a.TakeDmg(dmg);
        if (a.ReturnEnemyHealth() > 0)
            std::cout << "The " << a.ReturnName() << " has " << a.ReturnEnemyHealth() << " life points left."
                      << '\n';
    }
}

void fight::OpponentTurn(Player &p, Status &s, opponent & a) const {
    if (round % 2 == 0) {
        std::cout << '\n' << a.ReturnName() << " has attacked you and dealt " << a.ReturnEnemyDmg() << " dmg."
                  << '\n';
        s.LoseHealth(a.ReturnEnemyDmg());
        std::cout << "Your life is " << s.ReturnHealth() << "." << '\n';
    }
}

void fight::Attack(Player &p, Status &z, weapon &w) {
    std::cout << '\n' << "Would you like to fight this opponent? [y/n]" << '\n';
    char option;
    std::cin >> option;
    if (tolower(option) != 'y' && tolower(option) != 'n') {
        option = 'n';
        std::cout << '\n'
                  << "You did not select the right option! So you will just missed the opportunity to fight the enemy!"
                  << '\n';
    }
    if (tolower(option) == 'y') {
        opponent a(y);
        while (a.ReturnEnemyHealth() > 0 && z.ReturnHealth() > 0) {
            std::cout << '\n' << "~~~~~Round " << round << "~~~~~~~" << '\n';
            YourTurn(p,z,w,a);
           OpponentTurn(p,z,a);
            round++;
        }
    } else if (tolower(option) == 'n')
        std::cout << "You decided not to attack the " << y.ReturnName();
    z.Died(p);
        if (p.IsDead())
            throw (std::runtime_error("DEAD"));
}