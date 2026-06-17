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
    else if (choice =-5)
    {
        return new tahab();
    }
    return nullptr;
}

void execute_player_turn(vector<hero*>& my_team, vector<hero*>& enmy_team, int energy)
{
    cout << "current energy: " << energy << endl;
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

    int round = 0;
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

        if (is_game_over(team_1, team_2) || round >= 15) 
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

        execute_player_turn(team_2, team_1, energy_2);

        for (auto& h : team_2) 
        {
            h->update_cooldown();
        }

        if (is_game_over(team_1, team_2) || round >= 15) 
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