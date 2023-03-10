#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Ice : public AMateria
{

public:
	Ice();
	~Ice();
	void		use(ICharacter &target);
	AMateria*	clone(void) const;
};

#endif // ! ICE_H