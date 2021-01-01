#include "Headers/Player.h"
#include "Headers/Weapons.h"
#include "Headers/Opponent.h"
#include "Headers/Status.h"
#include "Headers/Fight.h"
#include "Headers/Choice.h"
#include "Headers/Stick.h"
#include "Headers/Sword.h"

int main() {
    auto p = Player::get_player();
    Status y;
    p->ShowPlayer();
    y.ShowInitStats( * p);
    weapon *d;
    //stick c;
    // d=&c;

    try {
            choice t(* p, y);
            t.Age3(* p, y);
            t.Age13(* p, y);
            sword s;
            d = &s;
            fight a;
            a.Attack(* p, y, *d);
    }
    catch (std::exception &) {
        std::cout << "\nYou have died!";
    }


    // choice t(p,y);
    //  t.Age3(p,y);
    //  t.Age13(p,y);

    return 0;
}