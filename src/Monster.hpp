#pragma once

#include <iostream>

#include "Card.hpp"

using namespace std;

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

string to_symbol(const Attribute &att ){
    switch(att){
        case Attribute::Dark:
            return u8"闇";
        case Attribute::Divine:
            return u8"神";
        case Attribute::Earth:
            return u8"地";
        case Attribute::Fire:
            return u8"炎";
        case Attribute::Light:
            return u8"光";
        case Attribute::Water:
            return u8"水";
        case Attribute::Wind:
            return u8"風";
        default: return "Invalid";
    }
}

class Monster : public Card
{
    public:
        Monster(
            string id, 
            string name,
            Attribute attribute , 
            string monster_type,
            int atk, 
            int def)
        :Card(std::move(id), CardType::Monster )
        , _attribute { attribute }
        , _monster_type { std::move(monster_type) }
        , _atk {atk}
        , _def {def}
        {
            set_name(move(name));
            _symbol = to_symbol(_attribute);
        }

        int get_atk() const { return _atk; }

        int get_def() const { return _def; }

        Attribute get_attribute() const { return _attribute;}

        string get_description() const
        { 
            return "["+_monster_type  +"]\n" + 
                    Card::get_description() + "\n"
                     "ATK/" + to_string(_atk) + " DEF/" + to_string(_def);
        }

    private:
        Attribute _attribute = {};
        string _monster_type;
        int _atk;
        int _def;
};
