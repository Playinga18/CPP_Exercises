#pragma once

#include <iostream>
#include <array>
#include "PC.h"
#include "Pokeball.h"

using namespace std;

// A person that captures Pokemons and makes them fight.
class Trainer
{
    public:
        Trainer(string name, PC pc);

        string name() const;

        const array<Pokeball, 6>& pokeballs() const;

    private:
        string _name;
        PC _pc;
        array<Pokeball, 6> _pokeballs;
};
