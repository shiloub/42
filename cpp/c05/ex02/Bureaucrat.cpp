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
	try
	{
		if (this->getGrade() == 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade --;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrement()
{
	try
	{
		if (this->getGrade() == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade ++;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " can not execute form " << form.getName() << " cuz " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << " grade " << rhs.getGrade();
	return (out);
}