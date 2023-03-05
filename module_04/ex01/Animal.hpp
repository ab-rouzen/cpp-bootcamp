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
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		const std::string&		getType(void) const;
	
	protected:
		std::string	type;
};

#endif // ! ANIMAL_H