#pragma once

#include <iostream>
#include <vector>

#include "Plush.hpp"
#include <optional>
#include <algorithm>

using namespace std;

class PlushStore{

public:
    PlushStore(string name)
        :_name {name}
    {}

    void loan(int value) { _money += value;}

    int make_plush(int value)
    {
        int tmp;
        if (_money > 0){
            if (_money <= value){
                tmp = _money;
                _money = 0;
            }else {
                tmp = value;
                _money -= value;
            }
            _exp += 1;
            _stock.emplace_back(Plush(tmp + _exp));
            return _stock[_stock.size()-1].get_cost();
        }
        return 0;
    }

    optional<Plush> buy(int value)
    {
        auto minPlushIter = min_element(_stock.begin(), _stock.end(), comparePlushByCost);
        if (minPlushIter == _stock.end() || minPlushIter->get_cost() > value) {
            return nullopt;
        }
        Plush minPlush = *minPlushIter;
        _money += minPlush.get_cost();
        _stock.erase(minPlushIter);
        return make_optional(minPlush);
    }

    int get_debt_amount() const { return (_money * 1/10) + _money;}

    string get_name() const {return _name;}

    int get_wealth_amount() const {return _money;}

    int get_stock_size() const  {return _stock.size();}

    int get_experience() const {return _exp;}


private:
    string _name;
    int _money = 0;
    int _exp = 0;
    vector<Plush> _stock;
};