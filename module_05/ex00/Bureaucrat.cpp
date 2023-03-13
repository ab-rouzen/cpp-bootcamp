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

Bureaucrat::~Bureaucrat()	{}

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
	//exception here
}

void	Bureaucrat::decrementGrade()
{
	if (grade >= 1  && grade < 150)
		++grade;
	// throw execption here
}
