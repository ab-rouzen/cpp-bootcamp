#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
		this->AForm::operator=(copy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::printExecuteMessage(const std::string &target) const
{
	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}