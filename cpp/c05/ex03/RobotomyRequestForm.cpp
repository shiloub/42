#include "RobotomyRequestForm.hpp"
#include "time.h"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 72, 45), _target("random"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : Form(cpy), _target(cpy._target){}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    if (this != &rhs)
    {
      this->_target = rhs._target;
      this->set_signed(rhs.getSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execAction() const 
{
  time_t timer;

  time(&timer);
  std::cout << "BRRRRR ZRK KRRRRRR BRRR BRR KRRRRRR PRRRRR\n";
	if (timer % 2 == 0)
    std::cout << this->_target << " has been robotomised\n";
  else
    std::cout << "robotomisation failed\n";
}