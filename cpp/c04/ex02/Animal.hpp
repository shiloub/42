#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
	public :
		Animal();
		virtual ~Animal();
		Animal(const Animal &animal);
		Animal &operator=(const Animal &rhs);
		virtual void	makeSound() const = 0;
		void	setType(const std::string type);
		std::string	getType() const;


	protected :
		std::string type;
};

#endif