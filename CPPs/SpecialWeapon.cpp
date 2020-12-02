#include <iostream>
#include <string>
#include "../Headers/SpecialWeapon.h"

void SpecialWeapon::GetWeapon(weapon &w, Status &s) {
    if (rand() % 1 == 0) {
        char option;
        if (w.ReturnWeap() == "sword") {
            std::cout << '\n' << "You can evolve the sword into Excalibur! It costs only 1500$!" << '\n';
            std::cout << "Do you wanna buy it? [y/n]" << '\n';
            std::cin >> option;
            if (tolower(option) != 'y' && tolower(option) != 'n') {
                option = 'n';
                std::cout << "You did not select an option so by default the option will be no! :( " << '\n';
            }
            if (tolower(option) == 'y') {
                if (s.ReturnWealth() >= 1500) {
                    s.ChangeStats(0, 0, 0, -1500);
                    this->name = "Excalibur";
                    this->max_dmg = 75;
                    this->min_dmg = 60;
                    std::cout << '\n' << "You evolved your weapon successfully! You have " << s.ReturnWealth()
                              << "$ left!"
                              << '\n';
                } else
                    std::cout << '\n' << "You don't have enough money!" << '\n';
            }
        }
        if (w.ReturnWeap() == "stick") {
            std::cout << '\n' << "You can evolve the stick into Nunchaku! It costs only 1000$!" << '\n';
            std::cout << "Do you wanna buy it? [y/n]" << '\n';
            std::cin >> option;
            if (tolower(option) != 'y' && tolower(option) != 'n') {
                option = 'n';
                std::cout << "You did not select an option so by default the option will be no! :( " << '\n';
            }
            if (tolower(option) == 'y') {
                if (s.ReturnWealth() >= 1000) {
                    s.ChangeStats(0, 0, 0, -1000);
                    this->name = "Nunchaku";
                    this->max_dmg = 50;
                    this->min_dmg = 40;
                    std::cout << '\n' << "You evolved your weapon successfully! You have " << s.ReturnWealth()
                              << "$ left!"
                              << '\n';
                } else
                    std::cout << '\n' << "You don't have enough money!" << '\n';
            }
        }
        if (w.ReturnWeap() == "dagger") {
            std::cout << '\n' << "You can evolve the dagger into Sica! It only costs 1100$!" << '\n';
            std::cout << "Do you wanna buy it? [y/n]" << '\n';
            std::cin >> option;
            if (tolower(option) != 'y' && tolower(option) != 'n') {
                option = 'n';
                std::cout << "You did not select an option so by default the option will be no! :( " << '\n';
            }
            if (tolower(option) == 'y') {
                if (s.ReturnWealth() >= 1100) {
                    s.ChangeStats(0, 0, 0, -1100);
                    this->name = "Sica";
                    this->max_dmg = 55;
                    this->min_dmg = 50;
                    std::cout << '\n' << "You evolved your weapon successfully! You have " << s.ReturnWealth()
                              << "$ left!"
                              << '\n';
                } else
                    std::cout << '\n' << "You don't have enough money!" << '\n';
            }
        }
        if (w.ReturnWeap() == "bow") {
            std::cout << '\n' << "You can evolve the bow into a crossbow! It only costs 1450$!" << '\n';
            std::cout << "Do you wanna buy it? [y/n]" << '\n';
            std::cin >> option;
            if (tolower(option) != 'y' && tolower(option) != 'n') {
                option = 'n';
                std::cout << "You did not select an option so by default the option will be no! :( " << '\n';
            }
            if (tolower(option) == 'y') {
                if (s.ReturnWealth() >= 1450) {
                    s.ChangeStats(0, 0, 0, -1450);
                    this->name = "crossbow";
                    this->max_dmg = 100;
                    this->min_dmg = 50;
                    std::cout << '\n' << "You evolved your weapon successfully! You have " << s.ReturnWealth()
                              << "$ left!"
                              << '\n';
                } else
                    std::cout << '\n' << "You don't have enough money!" << '\n';
            }
        }
        if (tolower(option == 'n'))
            std::cout << "You decided not to evolve your weapon!" << '\n';
    }
}

int SpecialWeapon::ReturnDmg() const {
    return weapon::ReturnDmg();
}

