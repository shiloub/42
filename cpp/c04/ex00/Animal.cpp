#include "Animal.hpp"

Animal::Animal()
{
	this->type = "random animal";
	std::cout << "Animal default constructor called\n";
}

Animal  &Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor called\n";
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called\n";
}

void	Animal::makeSound() const
{
		std::cout << "meowouf\n";
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::setType(const std::string type)
{
	this->type = type;
}