#include "Defs.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
: nameA(name), weaponA(weapon)
{
};

void	HumanA::attack()
{
	std::cout << nameA << " attacks with their " << weaponA.getType() << std::endl;
}
