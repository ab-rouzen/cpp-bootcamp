#include "Form.hpp"

Form::Form(std::string const &formName, int formSignGrade, int formExecGrade)
	: name(formName), signGrade(formSignGrade), executeGrade(formExecGrade)
{
	if (formSignGrade > 150 || formExecGrade > 150)
		throw (GradeTooHighException("Grade too high"));
	else if (formSignGrade < 1 || formExecGrade < 1)
		throw(GradeTooLowException("Grade too low"));
	isSigned = false;
}

Form::Form(const Form &copy)
	: name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	isSigned = copy.isSigned;
	whoTriedSign = copy.whoTriedSign;
	notSignedReason = copy.notSignedReason;
}

Form&	Form::operator=(const Form &copy)
{
	(void) copy;
	// nothing needs to be done here.
	return (*this);
}

Form::~Form()	{}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= signGrade)
	{
		isSigned  = true;
		whoTriedSign = b.getName();
	}
	else
		throw(GradeTooLowException("Grade too low"));
}

void	Form::signForm(void) const
{
	if (isSigned == true)
		std::cout << whoTriedSign << " signed " << name << "." << std::endl;
	else
		std::cout << whoTriedSign << " couldn't sign form " << name <<
		" because " << notSignedReason << "." << std::endl;
}
