#include "AMateria.hpp"

AMateria::AMateria(const std::string &typeName)
{
	type = typeName;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &copy)
{
	type = copy.type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Can't do anything to " << target.getName() << std::endl;
}

std::string const & AMateria::getType(void) const
{
	return (type);
}