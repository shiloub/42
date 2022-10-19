#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public :
		Brain();
		~Brain();
		Brain(std::string idea);
		Brain(const Brain &brain);
		Brain	&operator=(const Brain &rhs);
	private :
		std::string _ideas[100];
};

#endif