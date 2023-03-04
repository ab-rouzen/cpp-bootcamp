#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap halo("Goku");

	halo.attack("Freizer");
	halo.takeDamage(8);
	halo.beRepaired(4);
	halo.highFiveGuys();
	DiamondTrap Biji("Biji");
	Biji = halo;
	Biji.attack("Doom");
	Biji.ClapTrap::attack("Freizer");
	Biji.whoAmI();
	return 0;
}