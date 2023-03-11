#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	materiaCount = 0;
	//std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < materiaCount; i++)
		delete learnedMateria[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < materiaCount; i++)
	{
		learnedMateria[i] = copy.learnedMateria[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < materiaCount; i++)
		{
			learnedMateria[i] = copy.learnedMateria[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (materiaCount < 4 && m)
	{
		learnedMateria[materiaCount] =  m;
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