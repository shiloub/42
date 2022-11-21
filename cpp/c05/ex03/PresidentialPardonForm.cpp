#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential pardon", 25, 5), _target("random"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidential pardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : Form(cpy), _target(cpy._target){}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
    if (this != &rhs)
    {
      this->_target = rhs._target;
      this->set_signed(rhs.getSigned());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execAction() const 
{
  std::cout << "Zaphod Beeblebrox accorde son pardon à " << this->_target << std::endl;
}