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
		throw GradeTooHigh("Grade too high");
}

void	Bureaucrat::decrementGrade()
{
	if (grade >= 1  && grade < 150)
		++grade;
	else
		throw(GradeTooLow("Grade too low"));
}

GradeTooHigh::GradeTooHigh(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

GradeTooHigh::~GradeTooHigh()	throw() {}

const char*	GradeTooHigh::what() const throw()
{
	return (message.c_str());
}

GradeTooLow::GradeTooLow(std::string const &exceptionMsg) throw()
	: message(exceptionMsg)
{
}

GradeTooLow::~GradeTooLow()	throw() {}

const char*	GradeTooLow::what() const throw()
{
	return (message.c_str());
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (stream);
}
