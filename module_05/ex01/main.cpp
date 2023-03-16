#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int	main(void)
{
	Bureaucrat	Tom("Tom", 3);
	Form		b4("B4", 20, 11);


	std::cout << Tom << std::endl;
	std::cout << b4 << std::endl;
	b4.signForm();
	b4.beSigned(Tom);
	b4.signForm();
	try
	{
		//Tom.incrementGrade();
		Tom.decrementGrade();
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (GradeTooLowException &e)
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