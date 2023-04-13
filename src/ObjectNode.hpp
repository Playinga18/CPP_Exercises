#pragma once

#include "Node.hpp"

#include <map>

class ObjectNode : public Node
{
    public:
        ObjectNode();

        string print() const override;

    private:
        map<std::string, NodePtr> _data;
};