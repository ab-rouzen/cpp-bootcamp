#include "Ice.hpp"

Ice::Ice() 
	: AMateria("ice")
{

}

Ice::~Ice() {}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return new Ice();
}
