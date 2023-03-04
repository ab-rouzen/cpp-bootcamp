#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <string>
#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(const std::string &myName);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &obj);
		ClapTrap &operator=(const ClapTrap &obj);
		virtual void	attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int	amount);

	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
};

#endif // ! CLAP_TRAP_H