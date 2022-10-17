#include "Zombie.hpp"
#include "main.hpp"

int main()
{
    Zombie *horde;

    horde = zombieHorde(4, "JOhny");
    horde[0].announce();
    horde[1].announce();
    horde[2].announce();
    horde[3].announce();
    horde[3].give_name("martine");
    horde[3].announce();
    horde[2].announce();
    delete[] horde;

    return 0;
}