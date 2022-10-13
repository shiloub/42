#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class	ClapTrap
{
	private :
		unsigned int	_hit_points;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;
		std::string 	_name;

	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap &rhs);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int	get_hit_point();
		unsigned int	get_energy_point();
		unsigned int	get_attack_damage();
		std::string		get_name();

		void	set_name(std::string name);
		void	set_hit_point(unsigned int hit_point);
		void	set_energy_point(unsigned int energy_point);
		void	set_attack_damage(unsigned int attack_damage);
};

#endif
