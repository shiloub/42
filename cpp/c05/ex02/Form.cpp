#include "Form.hpp"

Form::Form() : _name("random"), _signed(0), _to_sign(150), _to_exec(150){}

Form::Form(std::string name, int to_sign, int to_exec): _name(name), _signed(0), _to_sign(to_sign), _to_exec(to_exec)
{
	if (to_exec > 150 || to_sign > 150)
		throw Form::GradeTooLowException();
	if (to_exec <= 0 || to_sign <= 0)
		throw Form::GradeTooHighException();
}

Form::~Form(){}

Form::Form(const Form &cpy) : _name(cpy._name), _signed(cpy._signed), _to_sign(cpy._to_sign), _to_exec(cpy._to_exec){}

Form &Form::operator=(const Form &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{

	out << "Formulaire" << rhs.getName() << " can be signed from " << rhs.getToSign() << " and be exec from " << rhs.getToExec() << ".";
	if (rhs.getSigned() == 1)
		out << " Already signed";
	else
		out << " Not signed yet";
	return (out);
}

std::string Form::getName() const
{
	return (this->_name);
}

void	Form::set_signed(int value)
{
	this->_signed = value;
}

int Form::getSigned() const
{
	return (_signed);
}

int Form::getToExec() const
{
	return (_to_exec);
}

int Form::getToSign() const
{
	return (_to_sign);
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (this->_signed == 0)
		throw NotSigned();
	if (this->_to_exec < executor.getGrade())
		throw GradeTooLowException();
	this->execAction();
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_to_sign)
		throw Form::GradeTooLowException();
	else if (this->_signed == 1)
		throw Form::AlreadySigned();
	else
		this->_signed = 1;
}