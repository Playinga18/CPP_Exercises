#pragma once

#include <string>
#include <iostream>
#include <memory>

using namespace std;
class Pokemon;
using PokemonPtr = shared_ptr<Pokemon>;


// A creature that is cute and can fight other ones.
class Pokemon
{
    public:
        Pokemon(string name);
        Pokemon(const Pokemon& other);

        string name() const;

        int id() const;

        Pokemon& operator=(const Pokemon& other);

    private:
        string _name;
        int _id;
        static int _counter;
};