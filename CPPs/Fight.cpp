#include <iostream>
#include <string>
#include "../Headers/Fight.h"

fight::fight() {
    round = 1;

}

void fight::Attack(Status z, weapon &b) {
    std::cout << '\n' << "Would you like to fight this opponent? [y/n]" << '\n';
    char option;
    std::cin >> option;
    if (option == 'y') {
        opponent a(y);
        while (a.ReturnEnemyHealth() > 0 && z.ReturnHealth() > 0) {
            std::cout << '\n' << "~~~~~Round " << round << "~~~~~~~" << '\n';
            if (round % 2 == 1) {
                int dmg = b.ReturnDmg();
                std::cout << "You have attacked the " << a.ReturnName() << " and dealt " << dmg << " dmg." << '\n';
                if (b.ReturnWeap() != "fist") {
                    b.Use();
                    b.BreakWeapon();
                    if (b.ReturnWeap() != "fist")
                        std::cout << "Your " << b.ReturnWeap() << " has " << b.ReturnDur() << " durability left"
                                  << '\n';
                }
                a.TakeDmg(dmg);
                if (a.ReturnEnemyHealth() > 0)
                    std::cout << "The " << a.ReturnName() << " has " << a.ReturnEnemyHealth() << " life points left."
                              << '\n';
            }
            if (round % 2 == 0) {
                std::cout << '\n' << a.ReturnName() << " has attacked you and dealt " << a.ReturnEnemyDmg() << " dmg."
                          << '\n';
                z.LoseHealth(a.ReturnEnemyDmg());
                std::cout << "Your life is " << z.ReturnHealth() << "." << '\n';
            }
            round++;
        }
    } else
        std::cout << "You decided not to attack the " << y.ReturnName();

}