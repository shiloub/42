#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
	int i (1);
	unsigned long int j(0);

	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (ac > i)
	{
		std::string s = av[i++];
		while (j < s.size())
		{
			s[j] = toupper(s[j]);
			j++;
		}
		std::cout << s;
		if (ac <= i)
			std::cout << std::endl;
	}
	return (0);
}