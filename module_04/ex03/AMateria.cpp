#include "AMateria.hpp"

AMateria::AMateria(const std::string &typeName)
{
	type = typeName;
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	(void) copy;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Can't do anything to " << target.getName() << std::endl;
}

std::string const & AMateria::getType(void) const
{
	return (type);
}