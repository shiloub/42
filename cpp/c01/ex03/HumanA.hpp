#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string new_name, Weapon &new_weapon);
		~HumanA();
		void	attack();
	private :
		std::string	name;
		Weapon	&weapon;
};
#endif