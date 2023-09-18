#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
}

ASpell::~ASpell()
{
}

ASpell &ASpell::operator=(ASpell const &rhs)
{
    _name = rhs._name;
    _effects = rhs._effects;
    return (*this);
}

ASpell::ASpell(ASpell const &cpy)
{
    *this = cpy;
}

std::string ASpell::getEffects() const
{
    return (this->_effects);
}
std::string ASpell::getName() const
{
    return (this->_name);
}

void    ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}