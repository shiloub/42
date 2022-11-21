#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <fstream>

class Form;

class Bureaucrat
{
	private :
		Bureaucrat();
		const std::string _name;
		int _grade;
	
	public :
		Bureaucrat(const std::string, int);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &rhs);
		Bureaucrat(const Bureaucrat &copy);

		const	std::string getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();
		void	signForm(Form &form);
		void	executeForm(Form const & form);

		class GradeTooHighException : public std::exception
		{
			public :
				const char*    what() const throw()
				{
					return ("grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public :
				const char*    what() const throw()
				{
					return ("grade too low");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
#endif