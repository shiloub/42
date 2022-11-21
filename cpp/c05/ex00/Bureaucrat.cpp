#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("billy"), _grade(150){}
Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
	this->_grade = cpy._grade;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return (*this);
	this->~Bureaucrat();
	return *new(this) Bureaucrat(rhs);
}

void	Bureaucrat::increment()
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade --;
}

void	Bureaucrat::decrement()
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade ++;
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}



std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << " grade " << rhs.getGrade();
	return (out);
}