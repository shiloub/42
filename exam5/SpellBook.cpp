#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::SpellBook(const SpellBook &cpy){
    *this = cpy;
}
SpellBook::~SpellBook(){}
SpellBook &SpellBook::operator=(const SpellBook &rhs){
    this->_spellbook = rhs._spellbook;
    return (*this);
}
void    SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
        this->_spellbook[spell->getName()] = spell;
}

void SpellBook::forgetSpell(std::string const &spellname)
{
    this->_spellbook.erase(spellname);
}

ASpell* SpellBook::createSpell(std::string const &spellname)
{
    ASpell *tmp = NULL;
    if (this->_spellbook.find(spellname) != this->_spellbook.end())
        tmp = this->_spellbook[spellname];
    return (tmp);
}