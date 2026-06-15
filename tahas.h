#ifndef tahas_h
#define tahas_h

#include "Hero.h"

class tahas : public hero
{
    private:

        hero *hot_target;

    public:

        tahas() : hero("taha koochike", "healer", 500, 3, "hame dar jaye khod in mantaghe aloode ast !") , hot_target(nullptr) { }

        void use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

         void use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

};

#endif