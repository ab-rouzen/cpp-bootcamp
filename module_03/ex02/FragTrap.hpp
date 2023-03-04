#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

struct	FragTrap : public ClapTrap
{
	public:
		FragTrap(const	std::string &name);
		~FragTrap(void);
		FragTrap(const FragTrap &copy);
		FragTrap& operator=(const FragTrap &copy);
		void	highFiveGuys(void);
};

#endif // ! FRAG_TRAP_H