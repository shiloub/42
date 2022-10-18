#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap tomtom("tom");
	ScavTrap nana("nana");
	ScavTrap titi(nana);

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
	tomtom.guardGate();
	tomtom.takeDamage(99);
	tomtom.takeDamage(20);
	tomtom.guardGate();
	tomtom.beRepaired(1000);
}