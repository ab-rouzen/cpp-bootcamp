#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	materiaCount = 0;
}

MateriaSource::~MateriaSource() {}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (materiaCount < 4)
	{
		learnedMateria[materiaCount] = m;
		materiaCount++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < materiaCount; i++)
	{
		if (learnedMateria[i]->getType() == type)
			return (learnedMateria[i]->clone());
	}
	return (nullptr);
}