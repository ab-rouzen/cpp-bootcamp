#include "Character.hpp"

Character::Character(const std::string myName)
{
	//std::cout << "Character constructor called" << std::endl;
	name = myName;
	for (int i = 0; i < 4; i++)
		isEmpty[i] = true;

}

Character::~Character()
{
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (isEmpty[i] == false)
			delete slot[i];
	}
}

Character::Character(const Character &copy)
{
	name = copy.name;
	for (int i = 0; i < 4; i++)
	{
		isEmpty[i]= copy.isEmpty[i];
		if (isEmpty[i] == false)
			delete slot[i];
		if (copy.isEmpty[i] == false)
			slot[i] = copy.slot[i]->clone();
	}
}

Character&	Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		name = copy.name;
		for (int i = 0; i < 4; i++)
		{
			isEmpty[i]= copy.isEmpty[i];
			if (isEmpty[i] == false)
				slot[i]->~AMateria();
			if (copy.isEmpty[i] == false)
				slot[i] = copy.slot[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (isEmpty[i] == true)
		{
			slot[i] = m;
			isEmpty[i] = false;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && isEmpty[idx] == false)
		isEmpty[idx] = true;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && isEmpty[idx] == false)
		slot[idx]->use(target);
}