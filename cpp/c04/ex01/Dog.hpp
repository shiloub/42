#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public :
		Dog();
		~Dog();
		Dog(const Dog &Dog);
		Dog &operator=(const Dog &rhs);
		void	makeSound() const;

	private :
		Brain	*_brain;
};

#endif