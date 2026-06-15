#ifndef whitedoctor_h
#define whitedoctor_h

#include "hero.h"

class whitedoctor : public hero 
{
    private:
        hero* buffed_teammate;

    public:
    
        whitedoctor() : hero("doctor white", "healer", 550, 4, "biyaridash rooye miz... zande mimoone age shans biare.") 
        {
            buffed_teammate = nullptr;
        }

        void use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

        void use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;

        void use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) override;
};

#endif