#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	public :
		Cat();
		virtual ~Cat();
		Cat(const Cat &cat);
		Cat &operator=(const Cat &rhs);
		std::string	get_idea(int);
		void	set_idea(std::string, int);
		virtual void	makeSound() const;
	private :
		Brain	*_brain;
};

#endif