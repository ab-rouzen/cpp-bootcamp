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

#endif // ! BUREAUCRAT_H