#include "ArrayNode.hpp"

ArrayNode::ArrayNode()
{}

ArrayNode::ArrayNode(int size)
    : _size(size)
    {}

string ArrayNode::print() const
{
    std::string result = "[";
    for (unsigned i = 0; i < _array.size(); ++i)
    {
        if (i > 0)
            result += ';';
        result += _array[i]->print();
    }
    result += ']';
    return result;
}
