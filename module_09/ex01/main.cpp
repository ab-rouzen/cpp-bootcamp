#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	calc(argv[1]);
	std::cout << argv[1] << std::endl;
	std::cout << calc.getResult() << std::endl;
}