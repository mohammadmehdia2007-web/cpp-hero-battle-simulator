#ifndef dannygolang_h
#define dannygolang_h

#include "hero.h"

class dannygolang : public hero 
{
    private:

        int last_target_idx;
        int lock_count;
        hero* shielded_teammate;

    public:

        dannygolang() : hero("dny goleng", "defender", 600, 4, "hich kas az in khat rad nemishe !") 
        {
            last_target_idx = -1;
            lock_count = 0;
            shielded_teammate = nullptr;
        }

        void use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

        void use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;
        
        void use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;
};

#endif