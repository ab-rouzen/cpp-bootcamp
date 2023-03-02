#include "Defs.hpp"
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

Fixed::Fixed(const int &in)
{
	number = in << frac;
}

Fixed::Fixed(const float &fn)
{
	float tmp = fn * (1 << frac);
	tmp = roundf(tmp + 0.5);
	number = (int) tmp;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement operator" << " called" << std::endl;
	if (this != &f)
	{
		number = f.number;
	}
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return number;
}

float Fixed::toFloat(void) const
{
	return ((float) number / (1 << frac));
}

int	Fixed::toInt(void) const
{
	return (number >> frac);
}

std::ostream &operator<<(std::ostream &buf, const Fixed &f)
{
	buf << f.toFloat();
	return (buf);
}

void	Fixed::setRawBits(int const raw)
{
	number = raw;
}
