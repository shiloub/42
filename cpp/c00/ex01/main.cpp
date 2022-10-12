#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;
	std::string command;
	while (1)
	{   
		std::cout << "PLEASE ENTER A COMMAND (HELP if you need some)\n";
		if (std::getline(std::cin, command))
		{
			for (unsigned int i = 0; i < command.size(); i++)
				command[i] = toupper(command[i]);
		}
		else
			_Exit (0);
		if (!command.compare("HELP"))
			std::cout << "ADD to add a contact, SEARCH to list existing contacts, EXIT to exit(i guess)\n";
		if (!command.compare("ADD"))
			book.command_add();
		if (!command.compare("SEARCH"))
			book.command_search();
		if (!command.compare("EXIT"))
			break ;
		
	}
	return (0);
}