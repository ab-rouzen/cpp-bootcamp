#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor has been called." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor has been called." << std::endl;
	type = copy.type;
}

WrongCat&	WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
	{
		type = copy.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor has been called." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*** MEOWS ***" << std::endl;
}