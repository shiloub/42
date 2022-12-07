#include <iostream>
#include <string>
#include <stdlib.h>


int is_int(char *str)
{
	long n;
	char *endptr;

	n = strtol(str, &endptr, 10);
	if(*endptr == '\0' && str[0] != 0)
	{
		if (n > -2147483648 && n < 2147483647)
			return (1);
	}
	return (0);

}

int is_float(char *str)
{
	char *endptr;

	strtof(str, &endptr);
	if (*endptr == 'f' && str[0] != 'f' && *(endptr + 1) == 0 /*&& *(endptr - 1) >= '0' && *(endptr - 1) <= '9'*/)
	{
		return (1);
	}
	return 0;
}

int	is_char(char *str)
{
	if (((str[0] > 0 && str[0] < '0') || (str[0] > '9' && str[0] <= 127)) && str[1] == 0)
	{
		return (1);
	}
	
	return (0);
}

int	is_double(char *str)
{
	char *endptr;

	strtod(str, &endptr);
	if (*endptr == 0 && str[0] != 0)
	{
		return (1);
	}
	return (0);

}


void	display_from_int(int i)
{
	char c;

	c = static_cast<char> (i);
	if (isprint(c))
		std::cout << "char : " << c << std::endl;
	else
		std::cout << "char : non pritable\n";
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << static_cast<float>(i) << ".0f\n";
	std::cout << "double : " << static_cast<double>(i) << ".0\n";
	
}

void	display_from_double(char *str)
{
	double d = strtod(str, NULL);
	float f = static_cast<float> (d);
	int i = static_cast<int> (d);
	char c = static_cast<char> (i);
	if (isprint(c))
		std::cout << "char : " << c << std::endl;
	else
		std::cout << "char : non pritable\n";
	if (d >= -2147483648 && d <= 2147483647)
		std::cout << "int : " << i << std::endl;
	else
		std::cout << "int : overflow\n";
	std::cout << "float : " << f << "f\n";
	std::cout << "double : " << d;
	if (static_cast<double>(i) == d)
		std::cout << ".0";
	std::cout << "\n";
}
void	display_from_float(char *str)
{
	float f = strtod(str, NULL);
	double d = static_cast<double> (f);
	int i = static_cast<int> (f);
	char c = static_cast<char> (i);
	if (isprint(c))
		std::cout << "char : " << c << std::endl;
	else
		std::cout << "char : non pritable\n";
	if (d >= -2147483648 && d <= 2147483647)
		std::cout << "int : " << i << std::endl;
	else
		std::cout << "int : overflow\n";
	std::cout << "float : " << f << "f\n";
	std::cout << "double : " << d;
	if (static_cast<double>(i) == d)
		std::cout << ".0";
	std::cout << "\n";
}

void	display_from_char(char *str)
{
	int i;

	i = static_cast<int> (str[0]);
	display_from_int(i);
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./convert \"argument\"\n";
		return (0);
	}
	char *str = av[ac -1];
	if (is_int(str))
	{
		display_from_int(atoi(str));
		return (0);
	}
	if (is_char(str))
	{
		display_from_char(str);
		return (0);
	}
	if (is_double(str))
	{
		display_from_double(str);
		return (0);
	}
	if (is_float(str))
	{
		display_from_float(str);
		return (0);
	}
	std::cout << "bad parameter\n";
	return (0);
}