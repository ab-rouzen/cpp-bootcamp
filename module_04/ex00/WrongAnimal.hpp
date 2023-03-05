#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>
#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal &copy);
		~WrongAnimal(void);
		void	makeSound(void) const;
		const std::string&		getType(void) const;
	
	protected:
		std::string	type;
};

#endif // ! WRONG_ANIMAL_H