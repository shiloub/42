#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <iostream>

class	Harl
{
	public :
		Harl();
		~Harl();
		void complain(std::string level);
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Harl::*array[4])(void);
};

#endif