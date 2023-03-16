#ifndef	FORM_H
#define FORM_H

class Form;
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Form{
	public:
		Form(std::string const &formName, int formSignGrade, int formExecGrade);
		Form(const Form &copy);
		Form&	operator=(const Form &copy);
		~Form();
		void		beSigned(const Bureaucrat &b);
		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		bool		isFormSigned(void) const;

	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				isSigned;
};

std::ostream&	operator<<(std::ostream &stream, const Form &f);

#endif // ! FORM_H