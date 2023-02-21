#pragma once

#include <iostream>
#include "Card.hpp"

using namespace std;

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

string to_string(const TrapType &type)
{
    switch (type)
    {
        case TrapType::Normal:return "Normal";
        case TrapType::Continuous:return "Continuous";
        case TrapType::Counter:return "Counter";
        default:return "invalid";
    }
}

class Trap : public Card
{
    public :
        Trap(string id, string name, TrapType type)
        : Card(id, CardType::Trap)
        , _trap(type)
        {
            set_name(move(name));
             _symbol = u8"罠";
        }

        TrapType get_trap_type() const { return _trap; }

    private:
        TrapType _trap;
};