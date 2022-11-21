#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private :
		std::string const	_name;
		int					_signed;
		const int					_to_sign;
		const int					_to_exec;
		Form();

	public :
		Form(std::string name, int to_sign, int to_exec);
		virtual ~Form();
		Form(const Form &cpy);
		Form &operator=(Form const &rhs);

		std::string		getName() const;
		int				getSigned() const;
		int				getToSign() const;
		int				getToExec() const;
		void			set_signed(int value);
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execAction() const = 0;
		void			execute(Bureaucrat const &executor) const;
		

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

		class NotSigned : public std::exception
		{
			public :
				const char*    what() const throw()
				{
					return ("form not signed");
				}
		};

		class AlreadySigned : public std::exception
		{
			public :
				const char*    what() const throw()
				{
					return (" already signed");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif