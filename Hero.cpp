#include "hero.h"

hero::hero(string name, string role, int hp, int ult_cooldown, string ult_phrase) 
{
    this->name = name;
    this->role = role;
    this->max_hp = hp;
    this->hp = hp;
    this->ult_cooldown = ult_cooldown;
    this->current_cooldown = 0; 
    this->ult_phrase = ult_phrase;
    this->shield = 0;
    this->shield_turns = 0;
    this->damage_multiplier = 1.0;
    this->buff_turns = 0;
    this->hot_amount = 0;
    this->hot_turns = 0;
}

string hero::get_name() const { return name; }
int hero::get_hp() const { return hp; }
string hero::get_role() const { return role; }
int hero::get_current_cooldown() const { return current_cooldown; }
int hero::get_ult_cooldown() const { return ult_cooldown; }

void hero::apply_hot(int amount, int turns)
{
    this->hot_amount = amount;
    this->hot_turns = turns;
}

void hero::process_hot()
{
    if (hot_turns > 0 && !is_dead())
    {
        heal(hot_amount);
        cout << name << " received " << hot_amount << " HP from serome khoon! Remaining turns: " << hot_turns - 1 << endl;
        hot_turns--;
        if (hot_turns == 0)
        {
            hot_amount = 0;
        }
    }
}

void hero::reduce_hp(int damage) 
{
    if (shield > 0 && shield_turns > 0)
    {
        if (damage <= shield)
        {
            shield -= damage;
            cout << name << "'s shield absorbed " << damage << " damage! Remaining shield: " << shield << endl;
            return;
        }
        else
        {
            damage -= shield;
            cout << name << "'s shield absorbed " << shield << " damage and broke!" << endl;
            shield = 0;
            shield_turns = 0;
        }
    }

    hp -= damage;
    if (hp < 0) hp = 0; 
}

void hero::add_shield(int amount, int turns)
{
    shield = amount;
    shield_turns = turns;
}

void hero::decrease_shield_turn()
{
    if (shield_turns > 0)
    {
        shield_turns--;
        if (shield_turns == 0)
        {
            shield = 0;
            cout << name << "'s shield end!" << endl;
        }
    }
}

void hero::heal(int amount) 
{
    if (hp > 0) 
    { 
        hp += amount;
        if (hp > max_hp) 
        {
            hp = max_hp;
        }
    }
}

bool hero::is_dead() const { return hp <= 0; }

void hero::update_cooldown() 
{
    if (current_cooldown < ult_cooldown) 
    {
        current_cooldown++;
    }
}

bool hero::can_use_ultimate() const { return current_cooldown >= ult_cooldown; }
void hero::reset_ultimate() { current_cooldown = 0; }

void hero::display_status() const 
{
    cout << name << " (" << role << ") - hp: " << hp << "/" << max_hp << " | ult: " << current_cooldown << "/" << ult_cooldown << endl;
}

void hero::apply_damage_buff(double multiplier, int turns)
{
    this->damage_multiplier = multiplier;
    this->buff_turns = turns;
}

void hero::decrease_buff_turn()
{
    if (buff_turns > 0)
    {
        buff_turns--;
        if (buff_turns == 0)
        {
            damage_multiplier = 1.0;
            cout << name << "'s damage buff expired!" << endl;
        }
    }
}

double hero::get_damage_multiplier() const
{
    return damage_multiplier;
}