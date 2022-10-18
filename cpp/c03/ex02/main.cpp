#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main()
{
	FlagTrap tomtom("tom");
	FlagTrap nana("nana");
	FlagTrap titi(nana);

	titi.attack("boubi");
	std::cout << tomtom.get_name() << std::endl;
	std::cout << tomtom.get_hit_point() << std::endl;
	std::cout << tomtom.get_energy_point() << std::endl;
	std::cout << tomtom.get_attack_damage() << std::endl;

	nana.beRepaired(1);
	for (int i = 0; i < 10; i++)
	{
		tomtom.attack("nana");
		nana.takeDamage(1);
	}
	tomtom.attack("nana");
	nana.takeDamage(1);
	nana.beRepaired(1);
	tomtom.highFivesGuys();
	tomtom.takeDamage(99);
	tomtom.takeDamage(20);
	tomtom.highFivesGuys();
	tomtom.beRepaired(1000);
}