#include "IntLeaf.hpp"

IntLeaf::IntLeaf(int value)
    : _value(value)
    {}


string IntLeaf::print() const
{
    return to_string(_value);
}

int IntLeaf::data() const {return _value; }