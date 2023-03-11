#include "Cure.hpp"

Cure::Cure() 
	: AMateria("cure")
{
	//std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called" << std::endl;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return new Cure();
}
