#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include <memory>

#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

using namespace std;
using CardPtr = variant<unique_ptr<Monster>, unique_ptr<Spell>, unique_ptr<Trap>>;

class Board
{
    public:

        bool put(CardPtr card)
    {
        return visit([this](auto&& c)
        {
            if (c == nullptr)
            {
                return false;
            }

            auto& cards_count = get_cards_count(c->get_type());
            if (cards_count >= 5)
            {
                return false;
            }

            _cards.push_back(move(c));
            ++cards_count;

            return true;
        }, card);
    }

private:
    vector<CardPtr> _cards;
    int _monsters_count = 0;
    int _spells_or_traps_count = 0;
    int& get_cards_count(CardType type)
    {
        switch (type)
        {
        case CardType::Monster:
            return _monsters_count;

        case CardType::Spell:
        case CardType::Trap:
            return _spells_or_traps_count;
        }

        return _monsters_count;
    }
};