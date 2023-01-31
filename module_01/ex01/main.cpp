#include "Defs.hpp"

int	main(void)
{
	Zombie	*p;

	p = zombieHorde(7, "dealer");
	p[0].announce();
	p[4].announce();
	p[6].announce();
	delete [] p;
	// p[10000].announce();
}