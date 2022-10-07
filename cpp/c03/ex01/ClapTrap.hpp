#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class	ClapTrap
{
	private :
		std::string 	_name;
		unsigned int	_hit_points;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;

	public :
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap &rhs);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
