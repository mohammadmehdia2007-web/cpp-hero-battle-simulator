#ifndef hero_h
#define hero_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class hero 
{
    protected:

        string name;
        string role;
        int max_hp;
        int hp;
        int ult_cooldown;     
        int current_cooldown; 
        string ult_phrase;    
        int shield;
        int shield_turns;
        double damage_multiplier;
        int buff_turns;
        int hot_amount;
        int hot_turns;

    public:

        hero(string name, string role, int hp, int ult_cooldown, string ult_phrase);
        virtual ~hero() {}

        string get_name() const;
        int get_hp() const;
        int get_max_hp() const;
        string get_role() const;
        int get_current_cooldown() const;
        int get_ult_cooldown() const;
    
        void reduce_hp(int damage);
        void heal(int amount);
        bool is_dead() const;
        void update_cooldown(); 
        bool can_use_ultimate() const;
        void reset_ultimate(); 
        void add_shield(int amount, int turns);
        void decrease_shield_turn();
        void apply_damage_buff(double multiplier, int turns);
        void decrease_buff_turn();
        double get_damage_multiplier() const;
        void apply_hot(int amount, int turns);
        void process_hot();

        virtual void use_ability_1(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) = 0;

        virtual void use_ability_2(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) = 0;
        
        virtual void use_ultimate(vector<hero*>& my_team, vector<hero*>& enemy_team, int target_idx) = 0;
    
        void display_status() const;
};

#endif