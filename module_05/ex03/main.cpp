#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat		Tom("Tom", 15);
	AForm			*form;
	Intern			someone;

	form = someone.makeForm("shuberrr" , "Dope");
	form = someone.makeForm("shrubbery creation", "bingo");
	form->beSigned(Tom);
	std::cout << *form << std::endl;
	form->execute(Tom);
	return 0;
}
