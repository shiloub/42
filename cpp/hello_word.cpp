#include <iostream>
//#include <algorithm>
#include <string>

int main(int ac, char **av)
{
	int i (1);

	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (ac > i)
	{
		std::string s = av[i++];
		std::transform(s.begin(), s.end(), s.begin(), toupper);
		std::cout << s;
		if (ac <= i)
			std::cout << std::endl;
	}
	return (0);
}