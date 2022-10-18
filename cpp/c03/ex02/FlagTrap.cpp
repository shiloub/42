#include "FlagTrap.hpp"

FlagTrap::FlagTrap()
{
	std::cout << "Flagtrap constructor default called\n";
	this->set_name("random");
	this->set_attack_damage(30);
	this->set_energy_point(100);
	this->set_hit_point(100);
}

FlagTrap::FlagTrap(std::string name)
{
	std::cout << "Flagtrap assignement constructor called\n";
	this->set_name(name);
	this->set_attack_damage(30);
	this->set_energy_point(100);
	this->set_hit_point(100);
}

FlagTrap::FlagTrap(const FlagTrap &flagtrap) : ClapTrap(flagtrap)
{
	std::cout << "flagtrap copy constructor called\n";
	*this = flagtrap;
}

FlagTrap::~FlagTrap()
{
	std::cout << "Flagtrap destructor called\n";
}

FlagTrap	&FlagTrap::operator=(const FlagTrap &rhs)
{
	this->set_name(rhs.get_name());
	this->set_attack_damage(rhs.get_attack_damage());
	this->set_hit_point(rhs.get_hit_point());
	this->set_energy_point(rhs.get_energy_point());
	return (*this);
}

void FlagTrap::highFivesGuys()
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is dead\n";
		return;
	}
	std::cout << "High five ! (Please)\n";
}