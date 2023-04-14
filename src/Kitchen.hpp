#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <set>

#include "../lib/Unit.hpp"
#include "../lib/Ingredient.hpp"

using namespace std;

class Kitchen
{
    public:
        Kitchen() = default;
        const Unit& register_unit(const Unit& unit);
        const Unit* find_unit(const string& name) const;

    private:  
        set<Unit> _units;
        set<Ingredient> _ingredients;
};
