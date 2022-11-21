#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private : 
        std::string _target;
        ShrubberyCreationForm();

    public :
        ShrubberyCreationForm(std::string target);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        virtual void    execAction() const;
};

#endif