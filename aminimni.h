#ifndef aminimni_h
#define aminimni_h

#include "hero.h"

class aminimni : public hero 
{
    private:
        bool is_buffed;

    public:
        aminimni() : hero("amin imeni", "attacker", 500, 3, "yek... do... se... boom... che kasi mond? mohem nist...") 
        {
            is_buffed = false;
        }

        void use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

        void use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;
        
        void use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;
};

#endif