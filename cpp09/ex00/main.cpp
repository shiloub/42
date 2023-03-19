#include "main.hpp"


std::string get_date_pipe(std::string line)
{
	std::string date;
	int i(0);

	while (line[i] && line[i] != '|')
	{
		date.push_back(line[i]);
		i++;
	}
	return (date);
}

void	trim_spaces(std::string &date)
{
	while (date.back() == ' ')
		date.pop_back();
	while (date.front() == ' ')
		date.erase(0, 1);
}

std::string get_after_pipe(std::string line)
{
	std::string str;
	int i(0);

	while (line[i] && line[i] != '|')
		i++;
	if (line[i] == '|')
		i++;
	while (line[i])
	{
		str.push_back(line[i]);
		i++;
	}
	return (str);
}

int	check_date(std::string date)
{
	int count(0);
	int i(0);

	while (date[i])
	{
		if (date[i] == '-')
			count ++;
		i++;
	}
	if (count != 2)
		throw (std::runtime_error("Bad input"));
	return (1);
}

int	check_line(std::map<std::string, std::string> map, std::map<std::string, std::string>::const_iterator it, std::string date, std::string number)
{

	if (number.length() > 5 || atoi(number.c_str()) > 1000)
		throw (std::runtime_error("Number too large"));
	if (atof(number.c_str()) < 0)
		throw (std::runtime_error("Number under 0"));
	if (number == "")
		throw (std::runtime_error("Bad input"));
	return (1);
}

void    convert(std::map<std::string, std::string> map)
{
	std::string line;
	std::string date;
	std::string number;
	std::map<std::string, std::string>::const_iterator it;

	std::ifstream flux("input.txt");
	if (!flux)
	{
		std::cout << "impossible d'ouvrir le file input.txt\n";
		exit(0);
	}
	while (getline(flux, line))
	{
		date = get_date_pipe(line);
		trim_spaces(date);
		trim_spaces(number);
		number = get_after_pipe(line);
		it = map.find(date);
		if (it == map.end())
			it = map.upper_bound(date);
		try
		{
			if (check_line(map, it, date, number) && date != "date" && check_date(date))
				std::cout << date << " => " << number << " * " << it->second << " = " << strtof(number.c_str(), NULL) * strtof(it->second.c_str(), NULL) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}


int main()
{
	std::map<std::string , std::string> map = parsing();
	convert(map);
	// std::map<std::string, std::string>::const_iterator it;
	// it = map.begin();
	// while (it != map.end())
	// {
	//     std::cout << it->first << " / " << it->second << std::endl;
	//     it++;
	// }
	// it = map.lower_bound("2022-03-30");
	// if (it == map.begin() || it == map.end())
	//     std::cout << "error : no lower bound" << std::endl;
	// else
	//     std::cout << it->first << " donne " << it->second << std::endl;
}