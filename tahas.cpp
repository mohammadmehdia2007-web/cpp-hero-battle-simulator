#include "tahas.h"

void tahas::use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx)
{
    if(hot_target != nullptr)
    {
        hot_target->process_hot();
    }

    hero *low_hp_hero = nullptr;
    for(auto h : my_team)
    {
        if(!h->is_dead())
        {
            if(h->get_hp() < low_hp_hero->get_hp() || low_hp_hero == nullptr)
            {
                low_hp_hero = h;
            }
        }
    }

    if(low_hp_hero != nullptr)
    {
        cout << name << "used tighe tiz !! healed " << low_hp_hero->get_name() << " for 20 hp " << endl;
        low_hp_hero->heal(20);
    }

    if(target_idx < enemy_team.size() && !enemy_team[target_idx]->is_dead())
    {
        cout << "dealt 30 damage to " << enemy_team[target_idx]->get_name() << "." << endl;
        enemy_team[target_idx]->reduce_hp(30);
    }
}