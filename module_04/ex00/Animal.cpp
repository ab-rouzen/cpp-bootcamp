#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor has been called." << std::endl;
	type = "Random Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor has been called." << std::endl;
	type = copy.type;
}

Animal&	Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment operator has been called." << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor has been called." << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "* Random animal sound *" << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (type);
}