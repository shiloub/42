#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string _type;
    public:
        ATarget();
        ATarget(std::string type);
        ATarget(ATarget const &cpy);
        ATarget &operator=(ATarget const &rhs);
        virtual ~ATarget();

        std::string const &getType() const;
        virtual ATarget *clone() const  = 0;
        void    getHitBySpell(ASpell const &spell) const;
};
#endif