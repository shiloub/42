#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_point(10), _attack_damage(0)
{
	_name = "random";
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _hit_points(10), _energy_point(10), _attack_damage(0), _name(name)
{
	std::cout << "Initialisation constructor called\n";
}


ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name;
	this->_attack_damage = rhs._attack_damage;
	this->_energy_point = rhs._energy_point;
	this->_hit_points = rhs._hit_points;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "Copy constructor called\n";
	*this = claptrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is dead\n";
		return ;
	}
	if (this->_energy_point > 0)
		this->_energy_point--;
	else
	{
		std::cout << this->_name << " can't attack\n";
		return ;
	}
	std::cout << this->_name << " is attacking " << target << " causing " << this->_attack_damage << " damage\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is dead\n";
		return ;
	}
	if (amount >= this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << this->_name << " take " << amount << " damage\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is dead\n";
		return ;
	}
	if (this->_energy_point > 0)
		this->_energy_point--;
	else
	{
		std::cout << this->_name << " can't rest\n";
		return ;
	}
	std::cout << this->_name << " is resting\n";
	this->_hit_points += amount;
}