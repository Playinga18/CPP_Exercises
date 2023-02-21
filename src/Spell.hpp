#pragma once

#include <iostream>
#include "Card.hpp"

using namespace std;

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

string to_string(const SpellType &type)
{
    switch (type)
    {
        case SpellType::Normal: return "Normal";
        case SpellType::Equip: return "Equip";
        case SpellType::Continuous: return "Continuous";
        case SpellType::QuickPlay: return "Quick-Play";
        case SpellType::Field: return "Field";
        default: return "invalid";
    }
}

class Spell : public Card
{
    public:
        Spell(string id, string name, SpellType type)
        : Card(id, CardType::Spell)
        , _spell(type)
        {
            set_name(move(name));
            _symbol = u8"魔";
        }

        SpellType get_spell_type() const {return _spell;}

    private:
        SpellType _spell;
};
