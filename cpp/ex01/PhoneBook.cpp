#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	i = 0;
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

void	PhoneBook::add_contact(int index, std::string first_name, std::string last_name, std::string nick_name, std::string phone ,std::string secret)
{
	registred[(index - 1) % 8].take_info("", "", (index - 1) % 8 + 1);
	registred[(index - 1) % 8].take_info(first_name, "first", 0);
	registred[(index - 1) % 8].take_info(last_name, "last", 0);
	registred[(index - 1) % 8].take_info(nick_name, "nick", 0);
	registred[(index - 1) % 8].take_info(phone, "phone", 0);
	registred[(index - 1) % 8].take_info(secret, "secret", 0);
}

void	PhoneBook::command_add()
{
	std::string	entries[5];

	std::cout << "first name : ";
	std::getline(std::cin, entries[0]);
	// if (entries[0].size() == 0)
	// 	exit (0);
	std::cout << "last name : ";
	std::getline(std::cin, entries[1]);
	// if (entries[1].size() == 0)
	// 	exit (0);
	std::cout << "nickname : ";
	std::getline(std::cin, entries[2]);
	std::cout << "phone number : ";
	std::getline(std::cin, entries[3]);
	std::cout << "darkest secret : ";
	std::getline(std::cin, entries[4]);
	i++;
	add_contact(i, entries[0], entries[1], entries[2], entries[3], entries[4]);

}

void	PhoneBook::command_search(void)
{
	int	i = 0;
	while (i < 8)
	{
		if (registred[i].gindex() != 0)
			registred[i].print_line();
		i++;
	}
	i = 0;
	while (i <= 0 || i >= 9)
	{
		std::string buff;
		std::cout << "PLEASE ENTER A CONTACT INDEX : ";
		std::getline(std::cin, buff);
		i = std::stoi(buff);
		if (i >= 1 && i <= 8 && registred[i - 1].gindex() != 0)
		{
			registred[i - 1].print_infos();
			break ;
		}
	}
}
