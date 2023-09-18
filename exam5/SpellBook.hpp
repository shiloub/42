#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "ASpell.hpp"
#include <string>
#include <map>

class Aspell;

class SpellBook
{
    private :
        std::map<std::string, ASpell *> _spellbook;
        SpellBook(const SpellBook &cpy);
        SpellBook &operator=(const SpellBook &rhs);
    
    public :
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell*);
    void forgetSpell(std::string const &);
    ASpell* createSpell(std::string const &);

};
#endif