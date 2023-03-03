#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap halo("Goku");

	halo.attack("Freizer");
	halo.takeDamage(8);
	halo.beRepaired(4);
	halo.takeDamage(8);
	halo.takeDamage(8);
	halo.guardGate();
	ScavTrap Biji(halo);
	Biji.attack("Freizer");
	return 0;
}