#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor default called\n";
	this->setType("Dog");
	this->_brain = new Brain("Jouer");
}

Dog::Dog(const Dog &Dog)
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
	delete this->_brain;
}