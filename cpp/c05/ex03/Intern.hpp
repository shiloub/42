#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private :
		Form *(Intern::*array[3])(std::string);
		Form *createShrubbery(std::string target);
		Form *createRobot(std::string target);
		Form *createPardon(std::string target);

	public :
		Intern();
		Intern(const Intern &cpy);
		~Intern();
		Intern &operator=(const Intern & rhs);
		Form *makeForm(std::string name, std::string target);
};

#endif