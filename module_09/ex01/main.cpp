#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Check arguments." << std::endl;
		return (1);
	}
	try
	{
		RPN	calc(argv[1]);
		std::cout << calc.getResult() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}