#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor has been called." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor has been called." << std::endl;
	type = copy.type;
}

Dog&	Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor has been called." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "*** BARKS ***" << std::endl;
}