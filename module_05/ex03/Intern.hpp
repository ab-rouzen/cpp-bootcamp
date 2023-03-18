#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern&	operator=(const Intern &copy);
		~Intern();
		AForm*	makeForm(std::string const &formName, std::string const &formTarget);

	private:
		std::string validForm[3];
		AForm*		(Intern::*createForm[4]) (std::string const &formTarget) const;
		AForm*		createShrubbery(std::string const &formTarget) const;
		AForm*		createRobotomy(std::string const &formTarget) const;
		AForm*		createPresidential(std::string const &formTarget) const;
};

#endif // ! INTERN_H