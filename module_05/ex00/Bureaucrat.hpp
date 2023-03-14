#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class	Bureaucrat
{
	public:
		Bureaucrat(std::string const &bureaucratName, int bureaucratGrade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();
		Bureaucrat&	operator=(Bureaucrat const &copy);
		int					getGrade() const;
		const std::string&	getName() const;
		void				incrementGrade();
		void				decrementGrade();
	
	private:
		std::string const	name;
		int					grade;
};

class GradeTooHigh : public std::exception
{
	public:
		GradeTooHigh(std::string const &exceptionMsg) throw();
		~GradeTooHigh() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

class GradeTooLow : public std::exception
{
	public:
		GradeTooLow(std::string const &exceptionMsg) throw();
		~GradeTooLow() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &b);

#endif // ! BUREAUCRAT_H