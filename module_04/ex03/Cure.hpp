#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Cure : public AMateria
{

public:
	Cure();
	~Cure();
	void		use(ICharacter &target);
	AMateria*	clone(void) const;
};

#endif // ! CURE_H