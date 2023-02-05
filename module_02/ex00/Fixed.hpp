#ifndef	FIXED_H
#define	FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw); 

	private:
		int					number;
		static const int	frac = 8;
};

#endif	// FIXED_H