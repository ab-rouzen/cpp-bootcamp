#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &copy);
		WrongCat&	operator=(const WrongCat &copy);
		~WrongCat(void);
		void	makeSound(void) const;
};

#endif // ! WRONG_CAT_H