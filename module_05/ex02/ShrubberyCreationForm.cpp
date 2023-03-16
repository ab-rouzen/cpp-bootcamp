#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		this->AForm::operator=(copy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::printExecuteMessage(const std::string &target) const
{
	std::ofstream	myFile(target + "_shrubbery");

	std::cout << "executing..." << std::endl;
	if (myFile.is_open())
	{
		myFile << "000" << std::endl;
	}
}