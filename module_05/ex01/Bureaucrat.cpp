#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &bureaucratName, int bureaucratGrade)
	: name(bureaucratName)
{
	if (bureaucratGrade < 1)
		throw (GradeTooHighException("Grade too high"));
	if (bureaucratGrade > 150)
		throw (GradeTooLowException("Grade too low"));
	grade = bureaucratGrade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
	: name(copy.name)
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

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()	throw() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()	throw() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (stream);
}

void	Bureaucrat::signForm(Form &f) const
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
