#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Scavtrap constructor default called\n";
	this->set_name("random");
	this->set_attack_damage(20);
	this->set_energy_point(50);
	this->set_hit_point(100);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Scavtrap assignement constructor called\n";
	this->set_name(name);
	this->set_attack_damage(20);
	this->set_energy_point(50);
	this->set_hit_point(100);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap destructor called\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap &rhs)
{
	this->set_name(rhs.get_name());
	this->set_attack_damage(rhs.get_attack_damage());
	this->set_hit_point(rhs.get_hit_point());
	this->set_energy_point(rhs.get_energy_point());
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->get_hit_point() == 0)
	{
		std::cout << this->get_name() << " is dead\n";
		return ;
	}
	if (this->get_energy_point() > 0)
		this->set_energy_point(this->get_energy_point() - 1);
	else
	{
		std::cout << this->get_name() << " can't attack\n";
		return ;
	}
	std::cout << "Scavetrap " << this->get_name() << " is attacking " << target << " causing " << this->get_attack_damage() << " damage\n";
}