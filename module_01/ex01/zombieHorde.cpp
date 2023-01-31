#include "Defs.hpp"

Zombie	*zombieHorde(int	n, std::string name)
{
	Zombie	*zh;

	zh = new Zombie[n];
	for (int i = 0; i < n; i++)
		zh[i].initZombie(name);
	return (zh);
}