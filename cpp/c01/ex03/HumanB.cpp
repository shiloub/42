#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name), weapon(NULL)
{}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &new_weapon)
{
    this->weapon = &new_weapon;
}

void    HumanB::attack()
{
    if (!this->weapon)
        std::cout << name << " cant attack without weapon\n";
    else
        std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}
