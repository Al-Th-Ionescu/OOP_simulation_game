#include <iostream>
#include <string>
#include "../Headers/Fight.h"

fight::fight() {
    round = 1;

}

void fight::Attack(Player &p, Status &z, weapon &b) {
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
            if (round % 2 == 1) {
                int dmg = b.ReturnDmg();
                std::cout << "You have attacked the " << a.ReturnName() << " and dealt " << dmg << " dmg." << '\n';
                if (b.ReturnMinDmg() != 0) {
                    b.Use();
                    b.BreakWeapon();
                    if (b.ReturnMinDmg() != 0)
                        std::cout << "Your " << b.ReturnWeap() << " has " << b.GetDurability() << " durability left"
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
    } else if (tolower(option) == 'n')
        std::cout << "You decided not to attack the " << y.ReturnName();
    z.Died(p);
}