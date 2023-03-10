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

Character&	Character::operator=(const Character &copy)
{
	name = copy.name;
	equipCount = copy.equipCount;
	// TO DO: copy materia array
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	if (m && equipCount < 4)
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
	// needs more tests
}

void	Character::use(int idx, ICharacter& target)
{
	//std::cout << "idx : " << idx << " and count : " << equipCount << std::endl;
	if (idx >= 0 && idx < equipCount)
		slot[idx]->use(target);
}