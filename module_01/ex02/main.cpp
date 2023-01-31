#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string &rstr = str;
	std::string	*pstr = &str;

	std::cout << "Address of str   :" << &str << std::endl;
	std::cout << "Reference of str :" << &rstr << std::endl;
	std::cout << "Pointer of str   :" << pstr << std::endl;
	return 0;
}