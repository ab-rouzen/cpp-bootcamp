#include "Defs.hpp"

int	main(void)
{
	Zombie	one("fool");
	Zombie	*p;
	one.announce();
	randomChump("dude");
	p = newZombie("dealer");
	p->announce();
	delete p;
}