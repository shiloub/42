#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
class PhoneBook
{
    public:
		PhoneBook();
    	void	print_contact(int index);
		void	add_contact(int index, std::string first_name, std::string last_name, std::string nick_name, std::string phone ,std::string secret);
		void	command_add(void);
		void	command_search(void);

    private:
		Contact	registred[8];
		int		i;
};
#endif