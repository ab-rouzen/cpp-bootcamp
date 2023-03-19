#ifndef	FORM_H
#define FORM_H

class Form;
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Form{
	public:
		class	GradeTooHighException;
		class	GradeTooLowException;
		Form(std::string const &formName, int formSignGrade, int formExecGrade);
		Form(const Form &copy);
		Form&	operator=(const Form &copy);
		~Form();
		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		bool		isFormSigned(void) const;
		void		beSigned(const Bureaucrat &b);

	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				isSigned;
};

class Form::GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(std::string const &exceptionMsg) throw();
		~GradeTooHighException() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

class Form::GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(std::string const &exceptionMsg) throw();
		~GradeTooLowException() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};
std::ostream&	operator<<(std::ostream &stream, const Form &f);

#endif // ! FORM_H