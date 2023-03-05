#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor has been called." << std::endl;
	name = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor has been called." << std::endl;
	name = copy.name;
}

Cat&	Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		name = copy.name;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor has been called." << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << "*** MEOWS ***" << std::endl;
}