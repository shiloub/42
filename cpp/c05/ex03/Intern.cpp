#include "Intern.hpp"

Intern::Intern()
{
	array[0] = &Intern::createShrubbery;
	array[1] = &Intern::createRobot;
	array[2] = &Intern::createPardon;
}

Intern::Intern(const Intern &cpy)
{
	this->array[0] = cpy.array[0];
	this->array[1] = cpy.array[1];
	this->array[2] = cpy.array[2];
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern & rhs)
{
	this->array[0] = rhs.array[0];
	this->array[1] = rhs.array[1];
	this->array[2] = rhs.array[2];
	return (*this);
}

Form *Intern::createShrubbery(std::string target)
{
	ShrubberyCreationForm *new_form = new ShrubberyCreationForm(target);
	return (new_form);
}

Form *Intern::createRobot(std::string target)
{
	RobotomyRequestForm *new_form = new RobotomyRequestForm(target);
	return (new_form);
}

Form *Intern::createPardon(std::string target)
{
	PresidentialPardonForm *new_form = new PresidentialPardonForm(target);
	return (new_form);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string tab[3];
	tab[0] = "shrubbery creation";
	tab[1] = "robotomy request";
	tab[2] = "presidential pardon";

	for (int i = 0; i < 3; i++)
	{
		if (tab[i] == name)
		{
			return (((*this).*(array[i]))(target)); // synthaxe d'appel: (object).*(ptrToFunction) (arguments)
		}
	}
	std::cout << "Error : form doesnt exist\n";
	return (NULL);
}
