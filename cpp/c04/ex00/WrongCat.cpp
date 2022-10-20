#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->setType("WrongCat");
    std::cout << "WrongCat constructor default called\n";
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called\n";
    *this = WrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "OH LONNNNNG JOHNSON\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}