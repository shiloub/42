#include "main.hpp"

std::string get_date(std::string line)
{
	std::string date;
	int i(0);

	while (line[i] && line[i] != ',')
	{
		date.push_back(line[i]);
		i++;
	}
	return (date);
}

std::string get_after_comma(std::string line)
{
	std::string str;
	int i(0);

	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		i++;
	while (line[i])
	{
		str.push_back(line[i]);
		i++;
	}
	return (str);
}

std::map<std::string, std::string> parsing()
{
	std::string line;
	std::string date;
	std::string number;

	std::map<std::string, std::string> map;
	std::ifstream flux("data.csv");
	if (!flux)
	{
		std::cout << "impossible d'ouvrir le file data.csv\n";
		exit(0);
	}
	while (getline(flux, line))
	{
		date = get_date(line);
		number = get_after_comma(line);
		if (date != "date")
			map.insert(std::make_pair(date, number));
	}
	return (map);
}