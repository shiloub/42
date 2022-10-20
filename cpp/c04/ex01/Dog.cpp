#include "Dog.hpp"

Dog::Dog()
{
    this->setType("Dog");
    this->_brain = new Brain("Jouer");
    std::cout << "Dog constructor default called\n";
}

Dog::Dog(const Dog &Dog) : Animal()
{
    this->_brain = new Brain();
    *this = Dog;
    std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this == &rhs)
        return (*this);
    *this->_brain = *rhs._brain;
    this->type = rhs.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Ouaf.\n";
}

std::string Dog::get_idea(int index)
{
    if (index >= 0 && index <= 99)
		return (this->_brain->get_idea(index));
    return ("");
}

void    Dog::set_idea(std::string idea, int index)
{
    if (index >= 0 && index <= 99)
		this->_brain->set_idea(idea,index);
}

Dog::~Dog()
{
	delete (this->_brain);
    std::cout << "Dog destructor called\n";
}