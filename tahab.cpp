#include "tahab.h"

void tahab::use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (tagged_enemy != nullptr && ultimate_delay_turns > 0)
    {
        ultimate_delay_turns--;
        if (ultimate_delay_turns == 0)
        {
            if (!tagged_enemy->is_dead())
            {
                if (tagged_enemy->get_hp() < 360)
                {
                    tagged_enemy->reduce_hp(360);
                }
                else
                {
                    tagged_enemy->reduce_hp(200);
                }
            }
            tagged_enemy = nullptr;
        }
    }

    cout << name << " unleashed ragbar!" << endl;
    for (auto h : enemy_team) 
    {
        if (!h->is_dead()) 
        {
            h->reduce_hp(30);
            cout << h->get_name() << " took 30 damage from spray." << endl;
        }
    }
}

void tahab::use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (tagged_enemy != nullptr && ultimate_delay_turns > 0)
    {
        ultimate_delay_turns--;
        if (ultimate_delay_turns == 0)
        {
            if (!tagged_enemy->is_dead())
            {
                if (tagged_enemy->get_hp() < 360)
                {
                    tagged_enemy->reduce_hp(360);
                }
                else
                {
                    tagged_enemy->reduce_hp(200);
                }
            }
            tagged_enemy = nullptr;
        }
    }

    if (target_idx < enemy_team.size() && !enemy_team[target_idx]->is_dead()) 
    {
        enemy_team[target_idx]->reduce_hp(90);
        cout << name << " used x-ray on " << enemy_team[target_idx]->get_name() << " for 90 damage and hid!" << endl;
        is_hidden = true;
        hidden_turns = 1;
    }
}

void tahab::use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) 
{
    if (tagged_enemy != nullptr && ultimate_delay_turns > 0)
    {
        ultimate_delay_turns--;
        if (ultimate_delay_turns == 0)
        {
            if (!tagged_enemy->is_dead())
            {
                if (tagged_enemy->get_hp() < 360)
                {
                    tagged_enemy->reduce_hp(360);
                }
                else
                {
                    tagged_enemy->reduce_hp(200);
                }
            }
            tagged_enemy = nullptr;
        }
    }

    cout << "!!! ultimate !!! " << ult_phrase << endl;
    
    vector<hero*> alive_enemies;
    for (auto h : enemy_team)
    {
        if (!h->is_dead())
        {
            alive_enemies.push_back(h);
        }
    }

    if (alive_enemies.size() > 0)
    {
        int rand_idx = rand() % alive_enemies.size();
        tagged_enemy = alive_enemies[rand_idx];
        ultimate_delay_turns = 1;
        cout << tagged_enemy->get_name() << " has been tagged by Taha!" << endl;
    }

    reset_ultimate();
}

void tahab::reduce_hp(int damage)
{
    if (is_hidden && damage != 30)
    {
        cout << name << " is hidden the single target attack!" << endl;
        return;
    }

    hp -= damage;
    if (hp < 0) 
    {
        hp = 0; 
    }
}

void tahab::decrease_hidden_turn()
{
    if (is_hidden)
    {
        hidden_turns--;
        if (hidden_turns <= 0)
        {
            is_hidden = false;
            cout << name << " is no longer hidden!" << endl;
        }
    }
}