#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
	
	private:
		void	printExecuteMessage(const std::string &target) const;
};

#endif	// ! PRESIDENTIAL_PARDON_FORM_H