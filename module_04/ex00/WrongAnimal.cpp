#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor has been called." << std::endl;
	type = "Random WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor has been called." << std::endl;
	type = copy.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy assignment operator has been called." << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor has been called." << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* Random wrong animal sound *" << std::endl;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (type);
}