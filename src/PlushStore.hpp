#pragma once

#include <iostream>
#include <vector>

#include <Plush.hpp>
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
        int min = _stock[0].get_cost();
        for (unsigned int i = 1; i < _stock.size(); i++)
        {
            if ( _stock[min].get_cost() > _stock[i].get_cost()){
                min = i;
            }
        }
        auto tmp = _stock[min];
        if (tmp.get_cost() > value) {
            return nullopt;
        }
        _money += tmp.get_cost();
        _stock.erase(_stock.cbegin() + min);
        return make_optional(tmp);
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