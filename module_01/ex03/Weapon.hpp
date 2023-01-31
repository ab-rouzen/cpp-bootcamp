#ifndef WEAPON_H
#define WEAPON_H

#include "Defs.hpp"

class Weapon
{
	private:

	std::string	type;

	public:

	Weapon(std::string newType);
	const std::string	getType() const;
	void				setType(std::string newType);
};

#endif // !WEAPON_H
