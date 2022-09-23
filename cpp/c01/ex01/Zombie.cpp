#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "";
}

Zombie::~Zombie()
{
    std::cout << name << " die\n";
}

Zombie::Zombie(std::string s)
{
    name = s;
}

void    Zombie::give_name(std::string s)
{
    this->name = s;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie  *newZombie(std::string name)
{
    Zombie *newZ;
    newZ = new Zombie(name);
    return (newZ);
}

void randomChump( std::string name )
{
    Zombie *newZ = newZombie(name);
    newZ->announce();
    delete (newZ);
}