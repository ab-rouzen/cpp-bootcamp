#include "Ice.hpp"

Ice::Ice(const std::string &myName) 
	: AMateria(myName)
{

}

Ice::~Ice() {}

void	Ice::use(ICharacter &target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return new Ice(getType());
}
