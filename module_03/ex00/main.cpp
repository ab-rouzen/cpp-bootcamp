#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap halo("Goku");

	halo.attack("Freizer");
	halo.takeDamage(8);
	halo.beRepaired(4);
	halo.takeDamage(8);
	halo.takeDamage(8);

	return 0;
}