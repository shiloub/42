#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	// int	i = 0;
	// while (i < 8)
	// {
	// 	registred[i].Contact();
	// 	i++;
	// }
}
void	PhoneBook::print_contact(int index)
{
	int i = 0;
	while (i < 8)
	{
		if (registred[i].gindex() == index)
			registred[i].print_infos();
		i++;
	}
}