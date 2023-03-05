#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor has been called." << std::endl;
	name = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor has been called." << std::endl;
	name = copy.name;
}

Dog&	Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		name = copy.name;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor has been called." << std::endl;
}

void	Dog::makeSound(void)
{
	std::cout << "*** BARKS ***" << std::endl;
}