#include "Headers/Player.h"
#include "Headers/Weapons.h"
#include "Headers/Opponent.h"
#include "Headers/Status.h"
#include "Headers/Fight.h"
#include "Headers/Choice.h"
#include "Headers/SpecialWeapon.h"


int main() {
    Player p;
    Status y;
    p.ShowPlayer();
    y.ShowInitStats(p);
    weapon b;
    b.GetWeapon();
    SpecialWeapon c;
    c.GetWeapon(b, y);
    // fight a;
    //   a.Attack(p,y, c);

    //choice t(p,y);
    //   t.Age3(p,y);
    //  t.Age13(p,y);
    try {
        throw p.IsDead();
    }
    catch (...) {
        std::cout << "You have died!";
    }
    return 0;
}