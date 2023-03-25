#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Base*	generate(void)
{
	int var = rand() % 3;
	switch (var)
	{
	case 0:
		// std::cout << "generated A..." << std::endl;
		return new A();
		break;

	case 1:
		// std::cout << "generated B..." << std::endl;
		return new B();
		break;

	case 2:
		// std::cout << "generated C..." << std::endl;
		return new C();
		break;
	}
	return (0);
}

void	identify(Base*	type)
{
	if (dynamic_cast<A*> (type))
		std::cout << "This pointer is of class 'A'" << std::endl;
	else if (dynamic_cast<B*> (type))
		std::cout << "This pointer is of class 'B'" << std::endl;
	else if (dynamic_cast<C*> (type))
		std::cout << "This pointer is of class 'C'" << std::endl;
}

void	identify(Base&	type)
{
	try
	{
		(void) dynamic_cast<A&> (type);
		std::cout << "This reference is of class 'A'" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void) dynamic_cast<B&> (type);
			std::cout << "This reference is of class 'B'" << std::endl;
		}
		catch(const std::exception& e)
		{
			(void) dynamic_cast<C&> (type);
			std::cout << "This reference is of class 'C'" << std::endl;				
		}
		
	}
}
