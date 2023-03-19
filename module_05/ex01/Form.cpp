#include "Form.hpp"

Form::Form(std::string const &formName, int formSignGrade, int formExecGrade)
	: name(formName), signGrade(formSignGrade), executeGrade(formExecGrade)
{
	if (formSignGrade > 150 || formExecGrade > 150)
		throw(GradeTooLowException("Grade too low"));
	else if (formSignGrade < 1 || formExecGrade < 1)
		throw (GradeTooHighException("Grade too high"));
	isSigned = false;
}

Form::Form(const Form &copy)
	: name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	isSigned = copy.isSigned;
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
		isSigned  = true;
	else
		throw(GradeTooLowException("Grade too low"));
}

std::string Form::getName(void) const
{
	return (name);
}

int	Form::getSignGrade(void) const
{
	return (signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (executeGrade);
}

bool	Form::isFormSigned(void) const
{
	return (isSigned);
}

std::ostream&	operator<<(std::ostream &stream, const Form &f)
{
	stream << "Name          : " << f.getName() << std::endl; 
	stream << "Sign grade    : " << f.getSignGrade() << std::endl;
	stream << "Execute grade : " << f.getExecuteGrade() << std::endl;
	stream << "Signed status : " << f.isFormSigned() << std::endl;
	return (stream);
}

Form::GradeTooHighException::GradeTooHighException(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

Form::GradeTooHighException::~GradeTooHighException()	throw() {}

const char*	Form::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

Form::GradeTooLowException::~GradeTooLowException()	throw() {}

const char*	Form::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}
