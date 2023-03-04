#include "FragTrap.hpp"

int	main(void)
{
	FragTrap halo("Goku");

	halo.attack("Freizer");
	halo.takeDamage(8);
	halo.beRepaired(4);
	halo.takeDamage(8);
	halo.takeDamage(8);
	halo.highFiveGuys();
	FragTrap Biji("Biji");
	Biji = halo;
	Biji.attack("Doom");
	Biji.attack("Doom");
	return 0;
}