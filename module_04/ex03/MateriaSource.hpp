#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*learnedMateria[4];
		int			materiaCount;
	
	public:
		MateriaSource();
		~MateriaSource();
		void		learnMateria(AMateria *m);
		AMateria*	createMateria(std::string const & type);
};

#endif	// ! MATERIA_SOURCE_H