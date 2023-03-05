#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor has been called." << std::endl;
	name = "Random Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor has been called." << std::endl;
	name = copy.name;
}

Animal&	Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment operator has been called." << std::endl;
	if (this != &copy)
	{
		name = copy.name;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor has been called." << std::endl;
}

void	Animal::makeSound(void)
{
	std::cout << "* Random animal sound *" << std::endl;
}