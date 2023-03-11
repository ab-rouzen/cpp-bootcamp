#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor has been called." << std::endl;
	type = "Dog";
	myBrain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor has been called." << std::endl;
	type = copy.type;
	myBrain = new Brain();
}

Dog&	Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment operator has been called." << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor has been called." << std::endl;
	delete myBrain;
}

void	Dog::makeSound(void) const
{
	std::cout << "*** BARKS ***" << std::endl;
}