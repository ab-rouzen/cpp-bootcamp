#include "FragTrap.hpp"

int	main(void)
{
	FragTrap halo("Goku");

	halo.attack("Freizer");
	halo.takeDamage(8);
	halo.beRepaired(4);
	halo.highFiveGuys();
	FragTrap Biji("Biji");
	Biji = halo;
	Biji.attack("Doom");
	return 0;
}