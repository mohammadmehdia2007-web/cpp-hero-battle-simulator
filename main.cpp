#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "whitedoctor.h"
#include "aminimni.h"
#include "dannygolang.h"
#include "tahas.h"
#include "tahab.h"

using namespace std;

void print_hero_menu()
{
    cout << "1. doctor white  (healer)\n"
         << "2. amin imeni  (attacker)\n"
         << "3. dny goleng  (defender)\n"
         << "4. taha koochike (healer)\n"
         << "5. taha bozorge(attacker)\n";
}

hero* create_hero(int choice)
{
    if (choice ==1) 
    {
        return new whitedoctor();
    }
    else if (choice ==2)
    {
        return new aminimni();
    }
    else if (choice ==3)
    {
        return new dannygolang();
    }
    else if (choice ==4)
    {
        return new tahas();
    }
    else if (choice ==5)
    {
        return new tahab();
    }
    return nullptr;
}

void execute_player_turn(vector<hero*>& my_team, vector<hero*>& enemy_team, int energy)
{
    int current_energy = energy;
    bool end_turn = false;

    while (current_energy > 0 && !end_turn)
    {
        cout << "current energy: " << current_energy << endl;
        cout << "do you want to end your turn? (1 for yes, 0 for no): ";
        
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            end_turn = true;
            continue;
        }

        cout << "choose a hero to act:\n";
        for (size_t i = 0; i < my_team.size(); ++i) 
        {
            if (!my_team[i]->is_dead()) 
            {
                cout << i + 1 << ". " << my_team[i]->get_name() << " (hp: " << my_team[i]->get_hp() << " / " << my_team[i]->get_max_hp() << ")\n";
            }
        }
        
        int hero_choice;
        cout << "enter hero number: ";
        cin >> hero_choice;
        hero_choice--;

        if (hero_choice < 0 || hero_choice >= my_team.size() || my_team[hero_choice]->is_dead()) 
        {
            cout << "invalid choice !!\n";
            continue;
        }
        
        hero* active_hero = my_team[hero_choice];

        cout << "\nchoose action for " << active_hero->get_name() << ":\n"
             << "1. ability 1 (cost 2)\n"
             << "2. ability 2 (cost 3)\n"
             << "3. ultimate (cooldown: " << active_hero->get_current_cooldown() << "/" << active_hero->get_ult_cooldown() << ") (cost 5)\n"
             << "enter action number: ";
             
        int action_choice;
        cin >> action_choice;

        int required_energy = 0;
        
        if (action_choice == 1)
        {
            required_energy = 2;
        }
        else if (action_choice == 2)
        {
            required_energy = 3;
        }
        else if (action_choice == 3)
        {
            required_energy = 5;
        }
        else
        {
            cout << "invalid action!\n";
            continue;
        }

        if (current_energy < required_energy)
        {
            cout << "not enough energy !! required: " << required_energy << " available: " << current_energy << "\n";
            continue;
        }

        cout << "\nchoose a target:\n";

        for (size_t i = 0; i < enemy_team.size(); ++i) 
        {
            cout << i + 1 << ". " << enemy_team[i]->get_name();

            if (enemy_team[i]->is_dead()) 
            { 
                cout << " [dead]"; 
            }

            cout << "\n";
        }
        
        int target_idx;
        cout << "enter target number: ";
        cin >> target_idx;
        target_idx--;

        cout << "\n<-------------------------------->\n";
        if (action_choice == 1) 
        {
            active_hero->use_ability_1(my_team, enemy_team, target_idx);
            current_energy -= required_energy;
        } 
        else if (action_choice == 2) 
        {
            active_hero->use_ability_2(my_team, enemy_team, target_idx);
            current_energy -= required_energy;
        } 
        else if (action_choice == 3) 
        {
            if (active_hero->can_use_ultimate()) 
            {
                active_hero->use_ultimate(my_team, enemy_team, target_idx);
                current_energy -= required_energy;
            } 
            else 
            {
                cout << "ultimate is not ready yet !!\n";
            }
        }
        cout << "<--------------------------------->\n";

        bool all_dead = true;
        for (auto h : enemy_team)
        {
            if (!h->is_dead())
            {
                all_dead = false;
                break;
            }
        }
        
        if (all_dead)
        {
            break;
        }
    }
}


bool is_game_over(const vector<hero*>& team_1, const vector<hero*>& team_2)
{
    bool team_1_dead = true;
    for (const auto& h : team_1)
    {
        if (!h->is_dead())
        {
            team_1_dead = false;
            break;
        }
    }

    bool team_2_dead = true;
    for (const auto& h : team_2)
    {
        if (!h->is_dead())
        {
            team_2_dead = false;
            break;
        }
    }

    if (team_1_dead && team_2_dead)
    {
        cout << "\n>!>!> DRAW <!<!<!\n" << endl;
        return true;
    }
    if (team_1_dead)
    {
        cout << "\n>!>!> TEAM 2 WINS <!<!<!\n" << endl;
        return true;
    }
    if (team_2_dead)
    {
        cout << "\n>!>!> TEAM 1 WINS <!<!<!\n" << endl;
        return true;
    }
    return false;
}

void delete_heap(vector<hero*>& team)
{
    for(auto s : team)
    {
        delete s;
    }
}

void show_teams(const vector<hero*>& team_1, const vector<hero*>& team_2) 
{
    cout << "\n======= team 1 =======" << endl;

    for (const auto h : team_1) 
    {
        h->display_status();
    }

    cout << "======= team 2 =======" << endl;

    for (const auto h : team_2) 
    {
        h->display_status();
    }

    cout << "======================\n" << endl;
}

int main()
{
    srand(time(0));

    vector<hero*> team_1;
    vector<hero*> team_2;

    bool is_selected_team1[6] = {false}; 

    cout << "|=== team 1 select ===|" << endl;
    for (size_t i = 0; i < 3; i++) 
    {
        print_hero_menu();

        cout << "choose hero " << i + 1 << ": ";

        int choice;
        cin >> choice;

        while (choice < 1 || choice > 5 || is_selected_team1[choice])
        {
            if (choice < 1 || choice > 5)
            {
                cout << "invalid choice!\ntry again: ";
            }
            else
            {
                cout << "hero already selected !!\nchoose another hero: ";
            }
            cin >> choice;
        }

        is_selected_team1[choice] = true;
        team_1.push_back(create_hero(choice));
    }

    bool is_selected_team2[6] = {false}; 

    cout << "\n|=== team 2 select ===|" << endl;
    
    for (int i = 0; i < 3; i++) 
    {
        print_hero_menu();

        cout << "choose hero " << i + 1 << ": ";

        int choice;
        cin >> choice;

        while (choice < 1 || choice > 5 || is_selected_team2[choice])
        {
            if (choice < 1 || choice > 5)
            {
                cout << "invalid choice!\ntry again: ";
            }
            else
            {
                cout << "hero already selected !!\nchoose another hero: ";
            }
            cin >> choice;
        }

        is_selected_team2[choice] = true;
        team_2.push_back(create_hero(choice));
    }

    int round = 1;
    int energy_sequence_1[] ={5, 10}; 
    int energy_sequence_2[] ={8, 9,10}; 

    while(round < 15)
    {
        cout << "\n>!>!>!>!>!>!>!> round " << round << " <!<!<!<!<!<!<!<" << endl; 
        
        int energy_1 = ((round % 2) == 0) ? energy_sequence_1[1] : energy_sequence_1[0]; 

        cout << "\n--- team 1 turn ---" << endl;

        for (auto& h : team_1) 
        {
            h->update_cooldown();
        }

        execute_player_turn(team_1, team_2, energy_1);

        if (is_game_over(team_1, team_2) || round > 15) 
        {
            break;
        }

        int energy_2 = 10;

        if (round == 1)
        { 
            energy_2 = energy_sequence_2[0]; 
        }
        else 
        {
            if (round == 2) 
            {
                energy_2 = energy_sequence_2[1];
            }
            else
            {
                energy_2 = energy_sequence_2[2];
            }
        }

        cout << "\n--- team 2 turn ---" << endl;

        for (auto& h : team_2) 
        {
            h->update_cooldown();
        }

         execute_player_turn(team_2, team_1, energy_2);

        if (is_game_over(team_1, team_2) || round > 15) 
        {
            break;
        }

        show_teams(team_1 ,team_2);

        round++;
    }

    delete_heap(team_1);
    delete_heap(team_2);

    return 0;
}