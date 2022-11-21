#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private : 
        std::string _target;
        PresidentialPardonForm();

    public :
        PresidentialPardonForm(std::string target);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
        virtual void    execAction() const;
};

#endif