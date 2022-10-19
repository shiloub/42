#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	//...
// 	return 0;
// }

int main()
{
	// Animal	*tab[10];

	// for (int i = 0; i < 10; i++)
	// {
	// 	if (i < 5)
	// 		tab[i] = new Cat();
	// 	else
	// 		tab[i] = new Dog();
	// }
	// for (int i = 0; i < 10; i++)
	// 	delete tab[i];

	Cat basic;
	{
		Cat tmp(basic);
	}
}

