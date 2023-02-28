#include "Defs.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "b + c is " << (b + c) << std::endl;
	std::cout << "b * c is " << (b * c) << std::endl;
	std::cout << "c / b is " << (c / b) << std::endl;
	std::cout << "min b and c is " << min(b, c) << std::endl;
	std::cout << "max b and c is " << max(b, c) << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
