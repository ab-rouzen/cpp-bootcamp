#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &copy);
		Brain& operator=(const Brain &copy);

	private:
		std::string	ideas[100];
};

#endif // ! BRAIN_H