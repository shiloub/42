#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
	public :
		FlagTrap();
		FlagTrap(std::string name);
		FlagTrap(const FlagTrap &flagtrap);
		~FlagTrap();
		FlagTrap &operator=(const FlagTrap &rhs);
		void highFivesGuys();

	private :
};