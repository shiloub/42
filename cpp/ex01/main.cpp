#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;
	std::string command;
	while (1)
	{   
		std::cout << "PLEASE ENTER A COMMAND (HELP if you need some)\n";
		std::getline(std::cin, command);
		if (command.size() == 0)
			exit (0);
		std::transform(command.begin(), command.end(), command.begin(), toupper);
		if (!command.compare("HELP"))
			std::cout << "ADD to add a contact, SEARCH to list existing contacts, EXIT to exit(i guess)\n";
		if (!command.compare("ADD"))
			book.command_add();
		if (!command.compare("SEARCH"))
			book.command_search();
		if (!command.compare("EXIT"))
			break ;
		
	}
	//std::cout << std::setfill(' ') << std::setw(10) << "abcdefghijklmnopqrstuvwxyz" << "|" << "salut";
	// book.command_add();
	// book.command_add();
	// book.command_add();
	// book.print_contact(1);
	// book.print_contact(2);
	// book.print_contact(3);

	return (0);
}