#include <iostream>
#include "Span.hpp"

int	main()
{
	Span	foo(5);

	foo.addNumber(6);
	foo.addNumber(3);
	foo.addNumber(17);
	foo.addNumber(9);
	foo.addNumber(11);
	std::cout << foo.longestSpan() << std::endl;
	std::cout << foo.shortestSpan() << std::endl;
	return (0);
}
