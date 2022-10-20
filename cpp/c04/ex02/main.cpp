#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

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
	Animal	*tab[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			tab[i] = new Cat();
		else
			tab[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
		delete tab[i];
	
	Cat cat;
	Cat copy(cat);
	std::cout << copy.get_idea(30) << std::endl;  //copy et cat on leur brain par defaut (dormir)
	std::cout << cat.get_idea(30) << std::endl;
	cat.set_idea("Miauler", 30);
	std::cout << cat.get_idea(30) << std::endl;		// l'idee 30 de cat a change mais pas celle de copy
	std::cout << copy.get_idea(30) << std::endl;
	copy = cat;
	std::cout << copy.get_idea(30) << std::endl;  // en copiant cat , l idee 30 de copy change

	//Animal bug;
}

