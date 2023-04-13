#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

#include "Node.hpp"

class ArrayNode : public Node
{
    public:
        ArrayNode();
        ArrayNode(int size);

        string print() const override;

    private:
        int _size;
        vector<NodePtr> _array;
};