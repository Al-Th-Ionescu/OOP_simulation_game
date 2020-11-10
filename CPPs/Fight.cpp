#include <iostream>
#include <string>
#include "../Headers/Fight.h"

fight::fight() {
    round =1;
}

void fight::Attack(Status z) {
    std::cout << '\n' << "Would you like to fight this opponent? [y/n]" << '\n';
    char option;
    std::cin >> option;
    if (option == 'y') {
        while (y.ReturnEnemyHealth() > 0 && z.ReturnHealth() > 0) {
            std::cout <<'\n'<< "~~~~~Round " << round << "~~~~~~~" << '\n';
            if (round % 2 == 1) {
                int dmg = x.ReturnDmg();
                std::cout << "You have attacked the " << y.ReturnName() << " and dealt " << dmg << " dmg." << '\n';
                x.Use();
                std::cout << "Your " << x.ReturnWeap() << " has " << x.ReturnDur() << " durability left" << '\n';
                y.TakeDmg(dmg);
                if(y.ReturnEnemyHealth() > 0)
                std::cout << "The " << y.ReturnName() << " has " << y.ReturnEnemyHealth() << " life points left."
                          << '\n';
            }
            if (round % 2 == 0) {
                std::cout << '\n' << y.ReturnName() << " has attacked you and dealt " << y.ReturnEnemyDmg() << " dmg."
                          << '\n';
                z.LoseHealth(y.ReturnEnemyDmg());
                std::cout << "Your life is " << z.ReturnHealth() << "." << '\n';
            }
            round++;
        }
    }
    else
            std::cout << "You decided not to attack the " << y.ReturnName();

}