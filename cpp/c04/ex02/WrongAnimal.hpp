#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &WrongAnimal);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		void	makeSound() const;
		void	setType(const std::string type);
		std::string	getType() const;


	private :
		std::string type;
};

#endif