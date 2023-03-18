#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat				Tom("Tom", 15);
	//ShrubberyCreationForm	b4("B4");
	//RobotomyRequestForm		b4("B4");
	PresidentialPardonForm		b4("B4");


	std::cout << Tom << std::endl;
	std::cout << b4 << std::endl;
	try
	{
		//Tom.incrementGrade();
		//Tom.signForm(b4);
		b4.execute(Tom);
		//b4.beSigned(Tom);
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