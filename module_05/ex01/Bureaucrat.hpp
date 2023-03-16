#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

class Bureaucrat;
#include <iostream>
#include <string>
#include "Form.hpp"

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
		void				signForm(Form &f) const;

	
	private:
		std::string const	name;
		int					grade;
};

class GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(std::string const &exceptionMsg) throw();
		~GradeTooHighException() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

class GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(std::string const &exceptionMsg) throw();
		~GradeTooLowException() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &b);

// namespace Bureau {
// 	class	Bureaucrat;
// 	class	GradeTooHighException;
// 	class	GradeTooLowException;
// }

#endif // ! BUREAUCRAT_H