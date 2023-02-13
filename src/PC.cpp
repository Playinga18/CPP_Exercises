#include "PC.h"


PC::PC(){}

vector<PokemonPtr> PC::pokemons() const{ return _pokemon;}

void PC::transfer(PokemonPtr p)
    {
        _pokemon.push_back(p);
    }