#include "Defs.hpp"

void	Zombie::announce(void)
{
	std::cout << name << " : " << "BraiiinzzZZZ..." << std::endl; 
}

void	Zombie::initZombie(std::string zombieName)
{
	name = zombieName;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}
