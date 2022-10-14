#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap tomtom("tom");
	ScavTrap nana(tomtom);

	std::cout << "tom name = " << tomtom.get_name() << std::endl;
	std::cout << "nana attack damages = " << nana.get_attack_damage() << std::endl;
	nana.set_attack_damage(42);
	std::cout << "nana attack damages = " << nana.get_attack_damage() << std::endl;
	// ScavTrap nana("nana");

	// nana.beRepaired(1);
	// for (int i = 0; i< 10; i++)
	// {
	// 	tomtom.attack("nana");
	// 	nana.takeDamage(1);
	// }
	// tomtom.attack("nana");
	// nana.takeDamage(1);
	// nana.beRepaired(1);
	// tomtom.takeDamage(120);
	// tomtom.beRepaired(1000);
}