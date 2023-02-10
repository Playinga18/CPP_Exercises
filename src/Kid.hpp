#pragma once

#include <iostream>
#include "PlushStore.hpp"

using namespace std;

class Kid{
public:
    Kid(string name, int money)
    :_name {name}
    ,_money {money}
    {}

    string get_name() const {return _name;}

    int get_money() const {return _money;}

    void buy_plush(PlushStore store){
        auto op = store.buy(_money);
        if (op){
            _money -= op.value().get_cost();
        }
    }

private:
    string _name;
    int _money;
};

ostream& operator<<(ostream& os, const Kid& other) {
    return os << other.get_name() << " has " << other.get_money() << " euros.";
}