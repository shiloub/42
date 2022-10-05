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

	ici:
	std::cout << "first name : ";
	if (std::getline(std::cin, entries[0]))
		std::cout << "last name : ";
	else
		exit(0);
	if (std::getline(std::cin, entries[1]))
		std::cout << "nickname : ";
	else
		exit (0);
	if (std::getline(std::cin, entries[2]))
		std::cout << "phone number : ";
	else
		exit (0);
	if (std::getline(std::cin, entries[3]))
		std::cout << "darkest secret : ";
	else
		exit (0);
	if (std::getline(std::cin, entries[4]))
		i++;
	else
		exit (0);
	if (entries[0].size() == 0 || entries[1].size() == 0 || entries[2].size() == 0 || entries[3].size() == 0 || entries[4].size() == 0)
	{
		std::cout << "ERROR : AT LEAST ONE OF THE FIELDS IS EMPTY: CONTACT CANT BE REGISTRED\n";
		i--;
		goto ici;
	}
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
	if (registred[0].gindex() == 0)
	{
		std::cout << "NO EXISTING CONTACT\n";
		return ;
	}
	ici:
	i = 0;
	while (i <= 0 || i >= 9)
	{
		std::string buff;
		std::cout << "PLEASE ENTER A CONTACT INDEX : ";
		if (std::getline(std::cin, buff))
			;
		else
			exit (0);
		i = atoi(buff.c_str());
		if (i >= 1 && i <= 8 && registred[i - 1].gindex() != 0)
		{
			registred[i - 1].print_infos();
			break ;
		}
		else
		{
			std::cout << "INDEX NOT VALID\n";
			goto ici;

		}
	}
}
