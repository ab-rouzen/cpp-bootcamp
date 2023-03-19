#ifndef	AFORM_H
#define AFORM_H

class AForm;
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	AForm{
	public:
		class	FormUnsignedException;
		class	GradeTooHighException;
		class	GradeTooLowException;
		AForm(std::string const &formName,int formSignGrade, int formExecGrade);
		AForm(const AForm &copy);
		AForm&	operator=(const AForm &copy);
		virtual ~AForm();
		void			beSigned(const Bureaucrat &b);
		std::string		getName(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;
		bool			isFormSigned(void) const;
		void			execute(const Bureaucrat &executor) const;
		virtual void	printExecuteMessage(const std::string &target) const = 0;

	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				isSigned;
};

class	AForm::FormUnsignedException : public std::exception
{
	public:
		FormUnsignedException(const std::string &exceptionMessage) throw();
		~FormUnsignedException() throw();
		const char*	what() const throw();
	
	private:
		std::string const message;
};

class AForm::GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(std::string const &exceptionMsg) throw();
		~GradeTooHighException() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(std::string const &exceptionMsg) throw();
		~GradeTooLowException() throw();
		const char*	what() const throw();

	private:
		std::string const message;
};

std::ostream&	operator<<(std::ostream &stream, const AForm &f);

#endif // ! FORM_H