#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <time.h>
#include <stdlib.h>
//#include <random>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
	
	private:
		void	printExecuteMessage(const std::string &target) const;
};

#endif	// ! ROBOTOMY_REQUEST_FORM_H