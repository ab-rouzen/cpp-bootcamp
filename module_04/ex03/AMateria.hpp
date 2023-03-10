#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
class ICharacter;
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;

public:
	AMateria(const std::string &typeName);
	AMateria(const AMateria &copy);
	AMateria&	operator=(const AMateria &copy);
	virtual ~AMateria();
	std::string const &	getType(void) const;
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter &target);
};

#endif	// ! AMATERIA_H