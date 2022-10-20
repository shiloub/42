#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat &WrongCat);
		WrongCat &operator=(const WrongCat &rhs);
		void	makeSound() const;
};

#endif