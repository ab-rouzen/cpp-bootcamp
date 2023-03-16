#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		void	printExecuteMessage(const std::string &target) const;
	
	private:
};

#endif	// ! SHRUBBERY_CREATION_FORM_H