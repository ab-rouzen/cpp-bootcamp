#include "Iter.hpp"
#include <vector>
#include <iostream>

void	op(const int& n)
{
	std::cout << n << std::endl;
}

int	main(void)
{
	int	arr[2];
	
	arr[0] = 1;
	arr[1] = 3;
	iter(arr, 2, op);
	return (0);
}
