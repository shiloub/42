#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
class PhoneBook
{
    public:
		PhoneBook();
    	void	print_contact(int index);

    private:
		Contact	registred[8];
};
#endif