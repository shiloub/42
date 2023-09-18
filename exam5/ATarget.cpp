#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(std::string type) : _type(type)
{
}

ATarget::~ATarget()
{
}

ATarget &ATarget::operator=(ATarget const &rhs)
{
    _type = rhs._type;
    return (*this);
}

ATarget::ATarget(ATarget const &cpy)
{
    *this = cpy;
}

std::string const &ATarget::getType() const
{
    return (this->_type);
}

void    ATarget::getHitBySpell(const ASpell &spell) const
{
    std::cout << this->_type << " has been " << spell.getEffects() << "!\n";
}