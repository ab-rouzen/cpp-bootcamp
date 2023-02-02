#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string &rStr = str;
	std::string	*pStr = &str;

	std::cout << "Address of str   :" << &str << std::endl;
	std::cout << "Reference of str :" << &rStr << std::endl;
	std::cout << "Pointer of str   :" << pStr << std::endl;

	std::cout << "Value in str     :" << str << std::endl;
	std::cout << "Value in rStr    :" << rStr << std::endl;
	std::cout << "Value in pStr     :" << *pStr << std::endl;
	return 0;
}