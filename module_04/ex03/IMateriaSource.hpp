#ifndef IMATERIA_SOURCE_H
#define IMATERIA_SOURCE_H

#include "AMateria.hpp"
#include <string>

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};
		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif	// ! IMATERIA_SOURCE_H