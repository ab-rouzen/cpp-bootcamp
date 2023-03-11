#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor has been called." << std::endl;
	type = "Cat";
	myBrain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor has been called." << std::endl;
	type = copy.type;
	myBrain = new Brain();
}

Cat&	Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator has been called." << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor has been called." << std::endl;
	delete myBrain;
}

void	Cat::makeSound(void) const
{
	std::cout << "*** MEOWS ***" << std::endl;
}