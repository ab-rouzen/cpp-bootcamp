#ifndef	AFORM_H
#define AFORM_H

class AForm;
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	AForm{
	public:
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

std::ostream&	operator<<(std::ostream &stream, const AForm &f);

#endif // ! FORM_H