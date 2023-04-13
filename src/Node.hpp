#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "InstanceCounter.hpp"

using namespace std;

class Node;

using NodePtr = std::unique_ptr<Node>;



class Node : public InstanceCounter
{
public:
    virtual ~Node() = default;
    virtual string print() const = 0;

protected:
    Node();

private:

};
