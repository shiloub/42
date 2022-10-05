#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name)
{}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &new_weapon)
{
    this->weapon = &new_weapon;
}

void    HumanB::attack()
{
    std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}
