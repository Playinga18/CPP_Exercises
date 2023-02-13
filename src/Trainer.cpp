#include "Trainer.h"

Trainer::Trainer(string name, PC pc)
    :_name {name}
    ,_pc {pc}
    {}

string Trainer::name() const{return _name;}

const array<Pokeball, 6>& Trainer::pokeballs() const{ return _pokeballs; }