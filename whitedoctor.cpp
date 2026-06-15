#include "whitedoctor.h"
#include <cstdlib>

void whitedoctor::use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (buffed_teammate != nullptr)
    {
        buffed_teammate->decrease_buff_turn();
    }

    int rand_idx = rand() % my_team.size();
    if (!my_team[rand_idx]->is_dead()) 
    {
        my_team[rand_idx]->heal(40);
        cout << name << " used aspirin on " << my_team[rand_idx]->get_name() << " (healed 40 hp)." << endl;
    }
    if (target_idx < enemy_team.size() && !enemy_team[target_idx]->is_dead()) 
    {
        int final_damage = 40 * get_damage_multiplier();
        enemy_team[target_idx]->reduce_hp(final_damage);
        cout << "dealt " << final_damage << " damage to " << enemy_team[target_idx]->get_name() << "." << endl;
    }
}

void whitedoctor::use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (buffed_teammate != nullptr)
    {
        buffed_teammate->decrease_buff_turn();
    }

    if (target_idx < my_team.size() && !my_team[target_idx]->is_dead())
    {
        buffed_teammate = my_team[target_idx];
        buffed_teammate->apply_damage_buff(1.2, 2);
        cout << name << " used doping on " << buffed_teammate->get_name() << "! Damage increased by 20% for 2 rounds." << endl;
    }
}

void whitedoctor::use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (buffed_teammate != nullptr)
    {
        buffed_teammate->decrease_buff_turn();
    }

    cout << "!!! ultimate !!! " << ult_phrase << endl; 
    for (hero* h : my_team) 
    {
        if (h->is_dead()) 
        {
            h->heal(200); 
            cout << name << " revived " << h->get_name() << " with 200 hp!" << endl;
            break; 
        }
    }
    reset_ultimate();
}