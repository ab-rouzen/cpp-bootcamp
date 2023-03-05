#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy);
		~Animal(void);
		void	makeSound(void);
	
	protected:
		std::string	name;
};

#endif // ! ANIMAL_H