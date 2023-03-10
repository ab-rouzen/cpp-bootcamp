#include "Character.hpp"

Character::Character(const std::string myName)
{
	name = myName;
	equipCount = 0;
}

Character::~Character() {}

Character::Character(const Character &copy)
{
	name = copy.name;
	equipCount = copy.equipCount;
	// TO DO: copy materia array
}
std::string const & Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (equipCount < 4)
	{
		slot[equipCount] = m;
		equipCount++;
	}
}

void	Character::unequip(int idx)
{
	if (idx < equipCount && idx >= 0)
	{
		slot[idx] = nullptr;
		equipCount--;
	}
}