#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap halo("Goku");

	halo.attack("Freizer");
	halo.takeDamage(8);
	halo.beRepaired(4);
	halo.guardGate();
	ScavTrap Biji(halo);
	return 0;
}