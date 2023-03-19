#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

int	main(void)
{
	Bureaucrat	Tom("Tom", 150);
	Bureaucrat	Mohamed("Mohamed", 0);
	std::cout << Tom << std::endl;
	try
	{
		//Tom.incrementGrade();
		Tom.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
 		std::cout << "a standard exception has been caught" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	return 0;
}