#include "Cat.hpp"

Cat::Cat()
{
    this->setType("Cat");
    this->_brain = new Brain("Dormir");
    std::cout << "Cat constructor default called\n";
}

Cat::Cat(const Cat &cat) : Animal()
{
    this->_brain = new Brain();
    *this = cat;
    std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this == &rhs)
        return (*this);
    *this->_brain = *rhs._brain;
    this->type = rhs.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "OH LONNNNNG JOHNSON\n";
}

std::string Cat::get_idea(int index)
{
    if (index >= 0 && index <= 99)
		return (this->_brain->get_idea(index));
    return ("");
}

void    Cat::set_idea(std::string idea, int index)
{
    if (index >= 0 && index <= 99)
		this->_brain->set_idea(idea,index);
}

Cat::~Cat()
{
	delete (this->_brain);
    std::cout << "Cat destructor called\n";
}