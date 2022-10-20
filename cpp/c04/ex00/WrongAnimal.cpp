#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "random WrongAnimal";
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = WrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

void	WrongAnimal::makeSound() const
{
		std::cout << "meowouf\n";
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::setType(const std::string type)
{
	this->type = type;
}