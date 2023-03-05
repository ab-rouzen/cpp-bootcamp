#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog&	operator=(const Dog &copy);
		~Dog(void);
		void	makeSound(void) const;
};

#endif // ! DOG_H