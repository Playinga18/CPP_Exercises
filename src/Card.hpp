#pragma once

#include <iostream>

using namespace std;

enum class CardType
{
    Monster,
    Spell,
    Trap
};

string to_string( const CardType &type ){
    switch( type ) {
        case CardType::Monster:
            return "Monster";
        case CardType::Spell:
            return "Spell";
        case CardType::Trap:
            return "Trap";
        default: 
            return "invalid";
    }
}

class Card
{
    public:
        Card(const string id, const CardType type )
        : _id { id }
        , _type { type }
        {}

        explicit Card(const string id, const CardType type, const string &name, const string &description)
        : _id { id }
        , _type { type }
        , _name { name }
        , _description { description }
        {}

        string get_id() const { return _id;}

        CardType get_type() const { return _type;}

        string get_name() const { return _name; }

        string get_description() const { return _description; }

        string get_symbol() const { return _symbol; }

        void set_name(std::string name) { _name = std::move(name); }

        void set_description(std::string description) { _description = std::move(description); }
    private:
        string _id;
        CardType _type;
        string _name;
        string _description;

    protected:
        string _symbol;
};