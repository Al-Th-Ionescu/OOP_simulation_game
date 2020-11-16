#include "Headers/Player.h"
#include "Headers/Weapons.h"
#include "Headers/Opponent.h"
#include "Headers/Status.h"
#include "Headers/Fight.h"
#include "Headers/Choice.h"


int main() {
    Status y;
    y.showPlayer();
    y.ShowInitStats();
//    weapon b;
//    b.GetWeapon();
//    fight a;
//    a.Attack(y, b);
    choice t(y);
    return 0;
}