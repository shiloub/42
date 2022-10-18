#include "ClapTrap.hpp"

int main()
{
	ClapTrap tomtom("tom");
	ClapTrap nana("nana");
	ClapTrap titi(nana);

	titi.attack("boubi");
	nana.beRepaired(1);
	for (int i = 0; i < 10; i++)
	{
		tomtom.attack("nana");
		nana.takeDamage(1);
	}
	tomtom.attack("nana");
	nana.takeDamage(1);
	nana.beRepaired(1);
	tomtom.takeDamage(120);
	tomtom.beRepaired(1000);
}