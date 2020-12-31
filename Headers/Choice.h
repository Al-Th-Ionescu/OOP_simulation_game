#ifndef MAIN_CPP_CHOICE_H
#define MAIN_CPP_CHOICE_H

#include <iostream>
#include <string>
#include "Status.h"
#include "Player.h"

class choice {
    bool buff_hygiene = false;
    bool nerf_fun = false;

public:
    choice(Player &, Status &);

    ~choice() = default;

    static void VerifDead(Player&);

    void Nerf(Status&) const;

    void Buff(Status&) const;

    void Age3(Player &, Status &);

    void Age13(Player &, Status &) const;

    void cat_story(Player &, Status &) const;

    static void cat_story_result_yes(Player&,Status&) ;

    static void cat_story_result_no(Player&,Status&) ;

    void learn_words(Player &, Status &);

    void learn_words_result_yes(Player&,Status&);

    void learn_words_result_no(Player&,Status&) const;

    void rat_story(Player &, Status &);

    void rat_story_result_1(Player&,Status&) const;

    void rat_story_result_2(Player&,Status&);

    void helping_friend(Player &, Status &) const;

    static void helping_friend_result_1(Player&,Status&) ;

    static void helping_friend_result_2(Player&,Status&) ;

    static void helping_friend_result_3(Player&,Status&);

    void baby_story(Player &, Status &) const;

    void baby_story_result_yes(Player&, Status &) const;

    void baby_story_result_no(Player&, Status &) const;


};

#endif //MAIN_CPP_CHOICE_H
