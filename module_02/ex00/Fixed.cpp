#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor" << " called" << std::endl;
	number = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor" << " called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor" << " called" << std::endl;
	number = f.number;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement operator" << " called" << std::endl;
	if (this != &f)
	{
		number = 0;
	}
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Member function getRawBits()" << " called" << std::endl;
	return number;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Member function setRawBits()" << " called" << std::endl;
	number = raw;
}
