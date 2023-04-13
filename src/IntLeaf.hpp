#pragma once

#include "Leaf.hpp"
#include "Node.hpp"

using namespace std;

class IntLeaf : public Leaf
{

    public:
        IntLeaf(int value);

        string print() const override;

        int data() const;


    private:
        int _value;

};