#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int	main(void)
{
	Bureaucrat	Tom("Tom", 21);
	Form		b4("B4", 20, 11);

	std::cout << b4 << std::endl;
	Tom.signForm(b4);
	try
	{
		Tom.incrementGrade();
		b4.beSigned(Tom);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "caught an exception" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
 		std::cout << "a standard exception has been caught" << std::endl;
		std::cout << "it says: " << e.what() << std::endl;
	}
	std::cout << std::endl << b4 << std::endl;
	return 0;
}
