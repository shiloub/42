#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    public:
		Contact();
		Contact(int ind, std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		void	print_infos(void);
		int		gindex(void);
		void	print_line(void);
		void	take_info(std::string info, std::string witch, int ind);
    private:
    	int	index;
    	std::string first_name;
    	std::string last_name;
    	std::string nick_name;
    	std::string phone_number;
    	std::string darkest_secret;
};

#endif
