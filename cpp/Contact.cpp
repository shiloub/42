#include "Contact.hpp"
Contact::Contact()
{
	index = 0;
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	darkest_secret = "";
}
Contact::Contact(int ind, std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	index = ind;
	first_name = first;
	last_name = last;
	nick_name = nick;
	phone_number = phone;
	darkest_secret = secret;
}
void	Contact::print_infos(void)
{
	std::cout << "first name :" << first_name << std::endl;
	std::cout << "last_name : " << last_name << std::endl;
	std::cout << "nick : " << nick_name << std::endl;
	std::cout << "phone : " << phone_number << std::endl;
	std::cout << "secret : " << darkest_secret << std::endl;
}

int	Contact::gindex(void)
{
	return (index);
}