#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat				Tom("Tom", 15);
	ShrubberyCreationForm	c4("C4");
	RobotomyRequestForm		b4c("B4C");
	PresidentialPardonForm	b4("B4");

	std::cout << b4 << std::endl;
	try
	{
		Tom.signForm(c4);
		Tom.signForm(b4c);
		Tom.signForm(b4);
		Tom.executeForm(b4);
		b4.execute(Tom);

		//Tom.executeForm(b4);
		//b4.beSigned(Tom);
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