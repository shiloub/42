#include "Warlock.hpp"

Warlock::Warlock() : name("random"), title("random") {}
Warlock::Warlock(std::string namee, std::string titlee) : name(namee), title(titlee) {
    std::cout << this->name << ": This looks like another boring day.\n";
}
Warlock::~Warlock(){
    std::cout << this->name << ": My job here is done!\n";
}
Warlock &Warlock::operator=(Warlock const &rhs)
{
    this->name = rhs.name;
    this->title = rhs.title;
    return (*this);
}
Warlock::Warlock(Warlock const &cpy)
{
    *this = cpy;
}

const std::string Warlock::getName() const
{
    return (this->name);
}

const std::string Warlock::getTitle() const
{
    return (this->title);
}

void    Warlock::setTitle(const std::string title)
{
    this->title = title;
}

void    Warlock::introduce() const
{
    std::cout << this->name << ":  I am " << this->name << ", " << this->title << "!\n";
}

void    Warlock::learnSpell(ASpell *spell)
{
    if (spell)
        _spellbook.learnSpell(spell);
}

void    Warlock::forgetSpell(std::string spellname)
{
    this->_spellbook.forgetSpell(spellname);
}

void    Warlock::launchSpell(std::string spellname, ATarget &target)
{
    ASpell *spell = this->_spellbook.createSpell(spellname);
    if (spell != NULL)
        spell->launch(target);
}