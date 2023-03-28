#include "Array.hpp"
#include <iostream>
#include <string>
struct data	
{
	std::string	str;
	int			n;
	char		c;
};

int	main(void)
{
	Array<data>	m(7);
	data		tmp;
	tmp.str = "whatever";
	tmp.c = 'l';
	tmp.n = 42;
	for (int i = 0; i < 5; i++)
		m[i] = tmp;
	m[4].str = "dull";
	m[6].str = "dull";
	for (int i = 0; i < 5; i++)
		std::cout << m[i].c << std::endl;
	
	std::cout << "---------------" << std::endl;

	Array<data> j(m);
	for (int i = 0; i < 5; i++)
		std::cout << j[i].str << std::endl;
	std::cout << j[6].str << std::endl;
	
	int	*a = new int();
	std::cout << *a << std::endl;

	return (0);
}