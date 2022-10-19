#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor default called\n";
    this->setType("Cat");
    this->_brain = new Brain("Dormir");
}

Cat::Cat(const Cat &cat)
{
    std::cout << "Cat copy constructor called\n";
    *this = cat;
}

Cat &Cat::operator=(const Cat &rhs)
{
    this->_brain = new Brain();
    this->setType(rhs.getType());
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "OH LONNNNNG JOHNSON\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
	delete this->_brain;
}