#pragma once

#include <iostream>
#include <memory>
#include "Pokemon.h"

using namespace std;

// A ball where a Pokemon sleeps.
class Pokeball
{
    public:
        Pokeball();

        bool empty() const;

        Pokemon pokemon() const;

        void store(PokemonPtr addPokemon);

    private:
        bool _active = false;
        PokemonPtr _pokemon = nullptr;
};
