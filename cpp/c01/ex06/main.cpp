#include "Harl.hpp"

int order_level(std::string order)
{
	std::string tab[4];
	tab[0] = "DEBUG";
	tab[1] = "INFO";
	tab[2] = "WARNING";
	tab[3] = "ERROR";

	int i = 0;
	for (i = 0; i < 4 && tab[i] != order; i++){}
	if (tab[i] == order)
		return(i);
	else
		return(4);
	
}
int main(int ac, char **av)
{
	int i;
	std::string order;
	Harl harl;

	if (ac != 2)
	{
		std::cout << "I am confused :(\n";
		return (0);
	}
	if (ac == 2)
	{
		order = av[1];
		i = order_level(order);
		switch (i)
		{
			case 0:
				harl.complain("DEBUG");
				i++;
			case 1:
				harl.complain("INFO");
				i++;
			case 2:
				harl.complain("WARNING");
				i++;
			case 3:
				harl.complain("ERROR");
				break;
			case 4:
                std::cout << "random complaining";
                break;
				
		}
	}
}