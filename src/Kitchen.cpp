#include "Kitchen.hpp"
#include <utility>

const Unit& Kitchen::register_unit(const Unit& unit) {
    auto [it, emplaced] = _units.emplace(std::move(unit));
    return *it;
}

const Unit* Kitchen::find_unit(const string& name) const{
    const auto& it = _units.find(name, [](const auto& n, const auto& u) { return ;});
    return it != _units.end() ? &it->second : nullptr;    
}