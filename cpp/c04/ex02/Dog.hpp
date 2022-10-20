#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public :
		Dog();
		virtual ~Dog();
		Dog(const Dog &Dog);
		Dog &operator=(const Dog &rhs);
		std::string	get_idea(int);
		void	set_idea(std::string, int);
		virtual void	makeSound() const;
	private :
		Brain	*_brain;
};

#endif