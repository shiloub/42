#include "Weapon.hpp"

const std::string &Weapon::getType()
{
    const std::string &s = this->type;
    return (s);
}

Weapon::Weapon(){}
Weapon::Weapon(std::string s) : type(s)
{}
Weapon::~Weapon(){}
void    Weapon::setType(std::string new_type)
{
    this->type = new_type;
}
