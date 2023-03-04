#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(const std::string &myName);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap& operator=(const DiamondTrap &copy);
		void	whoAmI(void);

	private:
		std::string	name;	
};

#endif // ! DIAMOND_TRAP