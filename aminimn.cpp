#include "aminimni.h"
#include <cstdlib>

void aminimni::use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (target_idx < enemy_team.size() && !enemy_team[target_idx]->is_dead()) 
    {
        int damage = 55;

        if (is_buffed)
        {
            damage = 110;
        }

        if (enemy_team[target_idx]->get_hp() <= damage) 
        {
            damage *= 2; 
        }

        enemy_team[target_idx]->reduce_hp(damage);
        cout << name << " used bullet on " << enemy_team[target_idx]->get_name() << " for " << damage << " damage!!" << endl;

        if (enemy_team[target_idx]->is_dead())
        {
            is_buffed = true;
        }
    }
}

void aminimni::use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    int rand_idx = rand() % my_team.size();
    if (!my_team[rand_idx]->is_dead() && my_team[rand_idx] != this) 
    {
        my_team[rand_idx]->reduce_hp(25);
        this->heal(75);
        cout << name << " absorbed 25 hp from " << my_team[rand_idx]->get_name() << " and healed himself for 75 hp" << endl;
    }
}

void aminimni::use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    cout << "!!! ultimate !!! " << ult_phrase << endl; 
    int rand_enemy = rand() % enemy_team.size();

    if (!enemy_team[rand_enemy]->is_dead()) 
    {
        enemy_team[rand_enemy]->reduce_hp(250);
        cout << "dealt 250 explosive damage to " << enemy_team[rand_enemy]->get_name() << "!" << endl;
    }

    for (hero* h : my_team) 
    {
        if (h != this && !h->is_dead()) 
        {
            h->reduce_hp(30);
            cout << "friendly fire! " << h->get_name() << " took 30 damage." << endl;
        }
    }
    reset_ultimate(); 
}