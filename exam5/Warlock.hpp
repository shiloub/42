#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <string>
#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "SpellBook.hpp"

class ASpell;
class SpellBook;
class Warlock
{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock(Warlock const &cpy);
        Warlock &operator=(Warlock const &rhs);
        SpellBook _spellbook;

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        std::string const getName() const;
        std::string const getTitle() const;
        void    setTitle(std::string const title);
        void    introduce() const;
        void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget & target);
};
#endif