#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default brain constructor called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Graille";
}

Brain::Brain(std::string idea)
{
	std::cout << "assignement brain constructor called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Copy brain constructor called\n";
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "Default brain destructor called\n";
}

std::string	Brain::get_idea(int index)
{
	if (index >= 0 && index <= 99)
		return (this->_ideas[index]);
	return ("");
}

void	Brain::set_idea(std::string idea, int index)
{
	if (index >= 0 && index <= 99)
		this->_ideas[index] = idea;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}