#include "Defs.hpp"

HumanB::HumanB(std::string name)
: nameB(name)
{
};

void	HumanB::setWeapon(Weapon* weapon)
{
	weaponB = weapon;
}

void	HumanB::attack()
{
	std::cout << nameB << " attacks with their " << weaponB->getType() << std::endl;
}
