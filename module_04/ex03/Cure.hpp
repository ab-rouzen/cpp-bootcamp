#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Cure : public AMateria
{

public:
	Cure(const std::string &myName);
	~Cure();
	void		use(ICharacter &target) const;
	AMateria*	clone(void) const;
};

#endif // ! CURE_H