#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor has been called." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor has been called." << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constrcutor has been called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = copy.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain &copy)
{
	std::cout << "Brain copy assignment operator has been called." << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = copy.ideas[i];
		}
	}
	return (*this);
}
