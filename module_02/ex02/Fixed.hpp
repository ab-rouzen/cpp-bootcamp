#ifndef	FIXED_H
#define	FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &f);
		Fixed(const int &in);
		Fixed(const float &fn);
		~Fixed(void);
		Fixed &operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const; 
		Fixed	operator+(const Fixed &op2) const;
		Fixed	operator-(const Fixed &op2) const;
		Fixed	operator*(const Fixed &op2) const;
		Fixed	operator/(const Fixed &op2) const;
	
	private:
		int					number;
		static const int	frac = 8;
};

std::ostream &operator<<(std::ostream &buf, const Fixed &f);
Fixed		min(const Fixed &op1, const Fixed &op2);
Fixed		max(const Fixed &op1, const Fixed &op2);
#endif	// FIXED_H