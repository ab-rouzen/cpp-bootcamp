#include "Cure.hpp"

Cure::Cure(const std::string &myName) 
	: AMateria(myName)
{

}

Cure::~Cure() {}

void	Cure::use(ICharacter &target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return new Cure(getType());
}
