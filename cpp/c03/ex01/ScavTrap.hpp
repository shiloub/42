#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap &rhs);
		void attack(const std::string& target);

	private :
		std::string _oui;
};