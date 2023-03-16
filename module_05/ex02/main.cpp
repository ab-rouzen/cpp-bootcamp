#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat				Tom("Tom", 30);
	ShrubberyCreationForm	b4("B4");


	std::cout << Tom << std::endl;
	std::cout << b4 << std::endl;
	Tom.signForm(b4);
	b4.execute(Tom);
	try
	{
		//Tom.incrementGrade();
		b4.beSigned(Tom);
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
	return 0;
}