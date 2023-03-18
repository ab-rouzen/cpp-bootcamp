#include "Intern.hpp"

Intern::Intern()
{
	validForm[0] = "shrubbery creation";
	createForm[0] = &Intern::createShrubbery;
	validForm[1] = "robotomy request";
	createForm[1] = &Intern::createRobotomy;
	validForm[2] = "presidential pardon";
	createForm[2] = &Intern::createPresidential;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern &copy)
{
	(void) copy;
	return (*this);
}

AForm*	Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
	for (int i = 0; i < 3; i++)
		if (formName == validForm[i])
			return ((this->*createForm[i])(formTarget));
	std::cout << formName << " is not a valid Form type." << std::endl;
	return(nullptr);
}

AForm*	Intern::createShrubbery(std::string const &formTarget) const
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm*	Intern::createRobotomy(std::string const &formTarget) const
{
	return (new RobotomyRequestForm(formTarget));
}

AForm*	Intern::createPresidential(std::string const &formTarget) const
{
	return (new PresidentialPardonForm(formTarget));
}
