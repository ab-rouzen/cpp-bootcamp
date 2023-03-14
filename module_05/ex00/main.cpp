#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

int	main(void)
{
	Bureaucrat	Tom("Tom", 150);

	std::cout << Tom << std::endl;
	try
	{
		//Tom.incrementGrade();
		Tom.decrementGrade();
	}
	catch (GradeTooHigh &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (GradeTooLow &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "a standard exception has been caught" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	std::cout << Tom << std::endl;
	return 0;
}