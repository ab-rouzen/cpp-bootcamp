#include "Ice.hpp"

Ice::Ice() 
	: AMateria("ice")
{
	//std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor called" << std::endl;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return new Ice();
}
