#include "dannygolang.h"

void dannygolang::use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{

    if (target_idx < enemy_team.size() && !enemy_team[target_idx]->is_dead()) 
    {
        int damage = 20;

        if (target_idx == last_target_idx) 
        {
            damage = 20 * 1.6;
            cout << name << " triggered ghofli multipliers!" << endl;
        } else 
        {
            last_target_idx = target_idx;
        }
        enemy_team[target_idx]->reduce_hp(damage);

        cout << name << " used ghofli on " << enemy_team[target_idx]->get_name() << " for " << damage << " damage!" << endl;
    }
}

void dannygolang::use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{

    if (target_idx < enemy_team.size() && !enemy_team[target_idx]->is_dead()) 
    {
        enemy_team[target_idx]->reduce_hp(50);
        cout << name << " hit target " << enemy_team[target_idx]->get_name() << " with fil kosh for 50 damage." << endl;
    }

    hero* highest_hp_hero = nullptr;
    int highest_idx = -1;
    
    for (int i = 0; i < enemy_team.size(); i++) 
    {
        if (!enemy_team[i]->is_dead()) 
        {
            if (highest_hp_hero == nullptr || enemy_team[i]->get_hp() > highest_hp_hero->get_hp()) 
            {
                highest_hp_hero = enemy_team[i];
                highest_idx = i;
            }
        }
    }
    
    if (highest_hp_hero != nullptr && highest_idx != target_idx) 
    {
        highest_hp_hero->reduce_hp(50);
        cout << name << " hit highest hp enemy " << highest_hp_hero->get_name() << " with fil kosh for 50 damage." << endl;
    }
}

void dannygolang::use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{

    cout << "!!! ultimate !!! " << ult_phrase << endl;
    
    hero* lowest_hp_hero = nullptr;
    for (auto h : my_team)
    {
        if (!h->is_dead())
        {
            if (lowest_hp_hero == nullptr || h->get_hp() < lowest_hp_hero->get_hp())
            {
                lowest_hp_hero = h;
            }
        }
    }

    if (lowest_hp_hero != nullptr)
    {
        shielded_teammate = lowest_hp_hero;
        shielded_teammate->add_shield(250, 2);
        cout << name << " activated shield for " << shielded_teammate->get_name() << " for 250 units!" << endl;
    }
    
    reset_ultimate();
}