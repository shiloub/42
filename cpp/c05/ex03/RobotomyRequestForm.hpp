#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private : 
        std::string _target;
        RobotomyRequestForm();

    public :
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
        virtual void    execAction() const;
};

#endif