#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string new_name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &new_weapon);
	private :
		std::string	name;
		Weapon	*weapon;
};
#endif