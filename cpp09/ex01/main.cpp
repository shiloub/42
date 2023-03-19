#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <queue>

void    fonction(int &resultat, std::queue<char> &queue, char &c)
{
	if (c == '-')
	{
		while (queue.size() != 0)
		{
			resultat -= queue.front() - '0';
			queue.pop();
		}
	}
	if (c == '+')
	{
		while (queue.size() != 0)
		{
			resultat += queue.front() - '0';
			queue.pop();
		}
	}
	if (c == '/')
	{
		while (queue.size() != 0)
		{
			resultat /= queue.front() - '0';
			queue.pop();
		}
	}
	if (c == '*')
	{
		while (queue.size() != 0)
		{
			resultat *= queue.front() - '0';
			queue.pop();
		}
	}
	
}

int check_expression(std::string &calcul)
{
	int i(0);
	std::string valid("0123456789 +-/*");
	while (calcul[i])
	{
		if (valid.find_first_of(calcul[i]) == std::string::npos)
			return (0);
		if (calcul[i] == ' ')
			calcul.erase(i, 1);
		else
			i++;
	}
	return (1);
}
int check_expression_is_polish(std::string calcul)
{
	int i(0);
	std::string tokens("+-/*");

	while (calcul[i] && calcul[i + 1])
	{
		if (tokens.find_first_of(calcul[i]) != std::string::npos)
		{
			if (i == 0 || tokens.find_first_of(calcul[i - 1]) != std::string::npos || tokens.find_first_of(calcul[i + 1]) != std::string::npos)
				return (0);
		}
		i++;
	}
	if (tokens.find_first_of(calcul[i]) == std::string::npos)
		return (0);
	return (1);
}

int main(int ac, char **av) 
{
	if (ac != 2)
	{
		std::cout << "Im waiting one argument\n";
		return (0);
	}
	std::string calcul = av[1];
	int i(0);
	if (!check_expression(calcul))
	{
		std::cout << "Error : expression isnt valid\n";
		return (0);
	}
	if (!check_expression_is_polish(calcul))
	{
		std::cout << "Error : expression isnt a polish valid expression\n";
		return (0);
	}
	int resultat(calcul[0] - '0');
	calcul.erase(0, 1);

	std::queue<char> queue;
	while (calcul[i])
	{
		if (isdigit(calcul[i]))
			queue.push(calcul[i]);
		else if (calcul[i] != ' ')
			fonction(resultat, queue, calcul[i]);
		i++;
	}
	std::cout << resultat << std::endl;
}