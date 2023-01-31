#ifndef HUMAN_A
#define HUMAN_A

#include "Defs.hpp"

class	HumanA
{
	public:

	HumanA(std::string name, Weapon &weapon);
	void	setWeapon(std::string weaponName);
	void	attack();

	private:

	std::string	nameA;
	Weapon&		weaponA;
};

#endif // !HUMAN_A
#define HUMAN_A