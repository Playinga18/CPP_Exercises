#pragma once

#include "Node.hpp"
#include "Leaf.hpp"

class StringLeaf : public Leaf
{
    public:
        StringLeaf(string data);

        string print() const override;

        string data() const;

    private:
        string _data;
};