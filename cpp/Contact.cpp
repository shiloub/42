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
// Contact::Contact(int ind, std::string first, std::string last, std::string nick, std::string phone, std::string secret)
// {
// 	index = ind;
// 	first_name = first;
// 	last_name = last;
// 	nick_name = nick;
// 	phone_number = phone;
// 	darkest_secret = secret;
// }
void	Contact::print_infos(void)
{
	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last_name : " << last_name << std::endl;
	std::cout << "nick : " << nick_name << std::endl;
	std::cout << "phone : " << phone_number << std::endl;
	std::cout << "secret : " << darkest_secret << std::endl;
}
void	Contact::print_line(void)
{
	std::string first_cut;
	std::string last_cut;
	std::string nick_cut;

	first_cut = first_name;
	last_cut = last_name;
	nick_cut = nick_name;
	if(first_name.size() > 10)
	{
		first_cut[9] = '.';
		first_cut.resize(10);
	}
	if(last_name.size() > 10)
	{
		last_cut[9] = '.';
		last_cut.resize(10);
	}
	if(nick_name.size() > 10)
	{
		nick_cut[9] = '.';
		nick_cut.resize(10);
	}
	std::cout << std::setfill(' ') << std::setw(10) << index << "|";
	std::cout << std::setfill(' ') << std::setw(10) << first_cut << "|";
	std::cout << std::setfill(' ') << std::setw(10) << last_cut << "|";
	std::cout << std::setfill(' ') << std::setw(10) << nick_cut << "|" << std::endl;
}
void	Contact::take_info(std::string info, std::string witch, int ind)
{
	if (!witch.compare("first"))
		first_name = info;
	if (!witch.compare("last"))
		last_name = info;
	if (!witch.compare("nick"))
		nick_name = info;
	if (!witch.compare("phone"))
		phone_number = info;
	if (!witch.compare("secret"))
		darkest_secret = info;
	else if (ind != 0)
		index = ind;
}

int	Contact::gindex(void)
{
	return (index);
}