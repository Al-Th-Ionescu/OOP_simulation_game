#include "Headers/Player.h"
#include "Headers/Weapons.h"
#include "Headers/Opponent.h"
#include "Headers/Status.h"
#include "Headers/Fight.h"
#include "Headers/Choice.h"
#include "Headers/Stick.h"


int main() {
    Player p;
    Status y;
    p.ShowPlayer();
    y.ShowInitStats(p);
    weapon* d, *z, *q;
    stick c;
    d=&c;
    fight a;
    a.Attack(p,y, *d);

    //choice t(p,y);
    //   t.Age3(p,y);
    //  t.Age13(p,y);
    try {
        if(p.IsDead())
            throw(std::runtime_error("DEAD"));
    }
    catch (std::exception&) {
        std::cout << "You have died!";
    }
    return 0;
}