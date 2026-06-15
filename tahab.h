#ifndef tahab_h
#define tahab_h

#include "hero.h"

class tahab : public hero 
{
    private:
        bool is_hidden;
        int hidden_turns;
        hero* tagged_enemy;
        int ultimate_delay_turns;

    public:
        tahab() : hero("taha bozorge", "attacker", 500, 4, "in yeki baraye dadash koochikam bood. hala nobate toe ...") 
        {
            is_hidden = false;
            hidden_turns = 0;
            tagged_enemy = nullptr;
            ultimate_delay_turns = 0;
        }

        void use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override; 

        void use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

        void use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

        void reduce_hp(int damage);
};

#endif