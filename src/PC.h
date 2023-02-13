#pragma once

#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
    public:
        PC();

        vector<PokemonPtr> pokemons() const;

        void transfer(PokemonPtr p);

    private:
        vector<PokemonPtr> _pokemon;
};
