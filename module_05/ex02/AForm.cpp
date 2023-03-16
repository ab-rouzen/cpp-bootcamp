#include "AForm.hpp"

AForm::AForm(std::string const &formName, int formSignGrade, int formExecGrade)
	: name(formName), signGrade(formSignGrade), executeGrade(formExecGrade)
{
	if (formSignGrade > 150 || formExecGrade > 150)
		throw (GradeTooHighException("Grade too high"));
	else if (formSignGrade < 1 || formExecGrade < 1)
		throw(GradeTooLowException("Grade too low"));
	isSigned = false;
}

AForm::AForm(const AForm &copy)
	: name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	isSigned = copy.isSigned;
}

AForm&	AForm::operator=(const AForm &copy)
{
	(void) copy;
	// nothing needs to be done here.
	return (*this);
}

AForm::~AForm()	{}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= signGrade)
		isSigned  = true;
	else
		throw(GradeTooLowException("Grade too low"));
}

std::string AForm::getName(void) const
{
	return (name);
}

int	AForm::getSignGrade(void) const
{
	return (signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (executeGrade);
}

bool	AForm::isFormSigned(void) const
{
	return (isSigned);
}

std::ostream&	operator<<(std::ostream &stream, const AForm &f)
{
	stream << "Name          : " << f.getName() << std::endl; 
	stream << "Sign grade    : " << f.getSignGrade() << std::endl;
	stream << "Execute grade : " << f.getExecuteGrade() << std::endl;
	stream << "Signed status : " << f.isFormSigned() << std::endl;
	return (stream);
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= executeGrade)
		;
	else
		throw (GradeTooLowException("Grade too low"));
	printExecuteMessage(name);
}
