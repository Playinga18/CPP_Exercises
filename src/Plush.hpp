#pragma once

#include <iostream>
using namespace std;


class Plush
        {

public:
    Plush() = default;
    Plush(int value)
        : _peluche { value }
    {}

    int get_cost() const{ return _peluche;}

    void set_cost(int value){ _peluche = value;}

    bool operator==(const Plush& oth) {
        return this == &oth;
    }

private:
    int _peluche = 10;
        };

ostream& operator<<(ostream& os, const Plush& other) {
    return os << "Plush costs " << other.get_cost();
}

bool comparePlushByCost(const Plush& a, const Plush& b){
    return a.get_cost() < b.get_cost();
}
