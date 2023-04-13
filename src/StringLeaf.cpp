#include "StringLeaf.hpp"

StringLeaf::StringLeaf(string data)
    : _data(data)
    {}

string StringLeaf::print() const { return "\"" + _data +  "\"";}

string StringLeaf::data() const { return _data;}