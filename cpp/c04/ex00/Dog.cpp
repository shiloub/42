#include "Dog.hpp"

Dog::Dog()
{
	this->setType("Dog");
	std::cout << "Dog constructor default called\n";
}

Dog::Dog(const Dog &Dog) : Animal()
{
	std::cout << "Dog copy constructor called\n";
	*this = Dog;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->setType(rhs.getType());
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Ouaf.\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}