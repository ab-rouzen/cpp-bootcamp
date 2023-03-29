#include "Iter.hpp"
#include <vector>
#include <iostream>

void	op(int& n)
{
	n *= 2;
}

int	main(void)
{
	int	arr[2];
	
	arr[0] = 1;
	arr[1] = 3;
	iter(arr, 2, op);
	std::cout << "arr[0] = " << arr[0] << std::endl;
	std::cout << "arr[1] = " << arr[1] << std::endl;
	return (0);
}
