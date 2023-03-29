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
	for (int i = 0; i < 50; i++)
		std::cout << m[i].c << std::endl;
	
	std::cout << "---------------" << std::endl;

	Array<data> j;
	//std::cout << j[0].str << std::endl;
	j = (m);
	for (unsigned int i = 0; i < j.size(); i++)
		std::cout << j[i].str << std::endl;
	std::cout << j[6].str << std::endl;
		return (0);
}