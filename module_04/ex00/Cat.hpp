#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat&	operator=(const Cat &copy);
		~Cat(void);
		void	makeSound(void);
};

#endif // ! CAT_H