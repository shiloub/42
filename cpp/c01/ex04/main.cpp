#include "main.hpp"

int main(int ac, char **av)
{
	std::ifstream	infile(av[1]);
	if (ac != 4)
	{
		std::cout << "wrong number of argument\n";
		return (0);
	}
	if (!infile)
	{
		std::cout << "ERROR : CANT OPEN THE FILE\n";
		return (0);
	}
	sed(infile, av);
}
void	check_replace(std::string &line, std::string to_change, std::string by)
{
	size_t pos;

	pos = line.find(to_change.c_str());
	if (to_change == "")
		return ;
	while (pos != std::string::npos)
	{
		line.erase(pos, to_change.size());
		line.insert(pos, by);
		pos = line.find(to_change.c_str(), pos + 1);
	}
}

void	sed(std::ifstream &infile, char **av)
{
	std::string line;
	std::string outfile_name(av[1]);
	std::string to_change(av[2]);
	std::string by(av[3]);

	outfile_name += ".replace";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile)
	{
		std::cout << "ERROR : CANT OPEN/CREATE OUTFILE" << std::endl;
		exit (0);
	}
	while (std::getline(infile, line))
	{
		check_replace(line, to_change, by);
		outfile << line << std::endl;
	}
}