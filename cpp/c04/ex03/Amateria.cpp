#include "Amateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
    return (*this);
}

AMateria::AMateria(const AMateria &amateria)
{
    *this = amateria;
}

const std::string &AMateria::getType() const
{
    return(this->_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << this->_type << " shoot " << target->_name;
}