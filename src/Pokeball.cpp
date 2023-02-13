#include "Pokeball.h"

Pokeball::Pokeball() {_pokemon = nullptr;}

bool Pokeball::empty() const {return !_active;}

Pokemon Pokeball::pokemon() const {return *_pokemon;}

void Pokeball::store(PokemonPtr addPokemon) 
    {
        _pokemon =  move(addPokemon);
        _active = true;
    }