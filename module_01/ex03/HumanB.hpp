#ifndef HUMAN_B
#define HUMAN_B

#include "Defs.hpp"

class	HumanB
{
	public:

	HumanB(std::string name);
	void	setWeapon(Weapon* weapon);
	void	attack();

	private:

	std::string	nameB;
	Weapon*		weaponB;
};

#endif // !HUMAN_B
#define HUMAN_B