#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	std::cout << easyfind(vec, 4) << std::endl;
	// aborts here, because 7 is not found
	std::cout << easyfind(vec, 7) << std::endl;
}