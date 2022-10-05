#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon) : name(new_name), weapon(new_weapon)
{}

HumanA::~HumanA(){}

void    HumanA::attack()
{
    std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}
