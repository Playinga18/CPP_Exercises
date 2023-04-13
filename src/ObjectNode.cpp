#include "ObjectNode.hpp"

ObjectNode::ObjectNode() {}

string ObjectNode::print() const 
{
    string result = "{";
    bool first  = true;
    for (auto const& el : _data)
    {
        if (first)
            first = false;
        else
            result += ",";
        result += '"' + el.first + "\":";
        result += el.second->print();
    }
    result += '}';
    return result;
}