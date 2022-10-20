#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->setType("Cat");
    std::cout << "Cat constructor default called\n";
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "cat copy constructor called\n";
    *this = cat;
}

Cat &Cat::operator=(const Cat &rhs)
{
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
}