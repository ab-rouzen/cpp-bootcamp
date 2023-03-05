#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor has been called." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor has been called." << std::endl;
	type = copy.type;
}

Cat&	Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor has been called." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "*** MEOWS ***" << std::endl;
}