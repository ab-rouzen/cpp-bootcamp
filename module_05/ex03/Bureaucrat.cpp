#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &bureaucratName, int bureaucratGrade)
	: name(bureaucratName)
{
	grade = bureaucratGrade; 
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	grade = copy.grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
	{
		grade = copy.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

void	Bureaucrat::incrementGrade()
{
	if (grade > 1 && grade <= 150)
		--grade;
	else
		throw GradeTooHighException("Grade too high");
}

void	Bureaucrat::decrementGrade()
{
	if (grade >= 1  && grade < 150)
		++grade;
	else
		throw(GradeTooLowException("Grade too low"));
}

GradeTooHighException::GradeTooHighException(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

GradeTooHighException::~GradeTooHighException()	throw() {}

const char*	GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

GradeTooLowException::GradeTooLowException(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

GradeTooLowException::~GradeTooLowException()	throw() {}

const char*	GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (stream);
}

void	Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << "." << std::endl;
	}
	catch(std::exception)
	{
		std::cout << name << " couldn't sign form " << f.getName() <<
		" because his grade doesn't allow it." << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	if (form.isFormSigned() == true && getGrade() <= form.getExecuteGrade())
		std::cout << name << " executed " << form.getName() << "." << std::endl;
	else
		std::cout << name << " could not execute form "
		<< form.getName() << "." << std::endl; 
}