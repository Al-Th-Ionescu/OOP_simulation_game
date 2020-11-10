#include <iostream>
#include <string>
#include <time.h>
#include "Headers/Player.h"
#include "Headers/Weapons.h"
#include "Headers/Opponent.h"
#include "Headers/Status.h"
#include "Headers/Fight.h"
#include "Headers/Choice.h"


int main() {
    std::string name;
    Player x(name);
    Status y;
    x.showPlayer();
    y.showStats(x);
   fight a;
   a.Attack(y);

   // choice(x,y);
    return 0;
}