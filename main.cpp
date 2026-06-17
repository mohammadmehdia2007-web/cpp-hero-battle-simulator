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

        round++;
    }


    return 0;
}