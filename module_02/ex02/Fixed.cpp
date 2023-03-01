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
	//std::cout << number << std::endl;
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
	// int	tmp = f.getRawBits();
	// int	main = tmp >> FRAC;
	// int	frac = tmp << FRAC;
	// buf << main << '.' << frac;
	buf << f.toFloat();
	return (buf);
}

void	Fixed::setRawBits(int const raw)
{
	number = raw;
}

Fixed	Fixed::operator+(const Fixed &op2) const
{
	Fixed	tmp ;
	tmp.setRawBits(this->getRawBits() + op2.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &op2) const
{
	Fixed	tmp;
	tmp.setRawBits(this->getRawBits() - op2.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &op2) const
{
	Fixed	tmp;
	int result = this->getRawBits() * op2.getRawBits();
	tmp.setRawBits(result >> frac);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &op2) const
{
	Fixed	tmp;
	int result = this->getRawBits() / (op2.getRawBits() >> frac);
	tmp.setRawBits(result);
	return (tmp);
}

bool	Fixed::operator<(const Fixed &op2) const
{
	return (this->number < op2.number);
}

bool	Fixed::operator<=(const Fixed &op2) const
{
	return (this->number <= op2.number);
}

bool	Fixed::operator>(const Fixed &op2) const
{
	return (this->number > op2.number);
}

bool	Fixed::operator>=(const Fixed &op2) const
{
	return (this->number >= op2.number);
}

bool	Fixed::operator==(const Fixed &op2) const
{
	return (this->number == op2.number);
}

bool	Fixed::operator!=(const Fixed &op2) const
{
	return (this->number != op2.number);
}

Fixed&	Fixed::operator++()
{
	this->number += one;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->number += one;
	return tmp;
}

Fixed&	Fixed::operator--()
{
	this->number -= one;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->number -= one;
	return (tmp);
}

const Fixed&		Fixed::min(const Fixed &op1, const Fixed &op2)
{
	return (op1.getRawBits() > op2.getRawBits() ? op2 : op1);
}

const Fixed&		Fixed::max(const Fixed &op1, const Fixed &op2)
{
	return (op1.getRawBits() > op2.getRawBits() ? op1 : op2);
}

Fixed&				Fixed::min(Fixed &op1, Fixed &op2)
{
	return (op1.getRawBits() > op2.getRawBits() ? op2 : op1);
}

Fixed&				Fixed::max(Fixed &op1, Fixed &op2)
{
	return (op1.getRawBits() > op2.getRawBits() ? op1 : op2);
}
