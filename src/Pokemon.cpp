#include "Pokemon.h"
#include <algorithm>

int Pokemon::_counter = 0;

Pokemon::Pokemon(string name)
    :_name {name}
    {
        _id = ++_counter;
    }

Pokemon::Pokemon(const Pokemon& other)
    :_name {other._name}
    {
        _id = ++_counter;
    }

string Pokemon::name() const {return _name;}

int Pokemon::id() const {return _id;}

Pokemon& Pokemon::operator=(const Pokemon& other)
    {
        _name = other._name;
        _id = _counter;
        return *this;
    }