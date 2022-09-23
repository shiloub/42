#include "Weapon.hpp"
#include "HumanA.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    std::cout << std::endl;
    club.setType("some other type of club");
    bob.attack();
}

