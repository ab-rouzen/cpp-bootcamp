#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Ice : public AMateria
{

public:
	Ice(const std::string &myName);
	~Ice();
	void		use(ICharacter &target) const;
	AMateria*	clone(void) const;
};

#endif // ! ICE_H