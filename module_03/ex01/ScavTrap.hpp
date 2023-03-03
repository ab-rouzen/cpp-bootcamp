#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

struct	ScavTrap : ClapTrap
{
	public:
		ScavTrap(const	std::string &name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap &copy);
		ScavTrap& operator=(const ScavTrap &copy);
		void	guardGate(void);
};

#endif // ! SCAV_TRAP_H