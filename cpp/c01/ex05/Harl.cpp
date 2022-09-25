#include "Harl.hpp"


Harl::Harl()
{
	Harl::array[0] = &Harl::debug;
	Harl::array[1] = &Harl::info;
	Harl::array[2] = &Harl::warning;
	Harl::array[3] = &Harl::error;
}

Harl::~Harl(){}

void    Harl::complain(std::string level)
{
	std::string tab[4];
	tab[0] = "DEBUG";
	tab[1] = "INFO";
	tab[2] = "WARNING";
	tab[3] = "ERROR";

	int i = 0;
	for (i = 0; i < 4 && tab[i] != level; i++){}
	if (tab[i] == level)
		(this->*array[i])();
	else
		std::cout << "random message\n";

}

void Harl::debug()
{
	std::cout << "oh Zinédine, pas ça, pas ça Zinédine !\n";
}

void Harl::info()
{
	std::cout << "Oh non pas ça, pas aujourd'hui !\n";
}
void Harl::warning()
{
	std::cout << "Pas maintenant !\n";
}
void Harl::error()
{
	std::cout << "Pas après tout ce que tu as fait !\n";
}