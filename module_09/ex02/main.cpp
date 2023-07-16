#include "PmergeMe.hpp"
#include "GroupIterator.hpp"
#include "Defs.hpp"
#include <iostream>
#include <vector>
#include <sstream>

template<class C>
void	print_numbers(C container_type)
{
	typename C::const_iterator	itb = container_type.begin();	
	typename C::const_iterator	ite = container_type.end();
	for (; itb != ite; itb++)
		std::cout << *itb << " ";
}

void	insert_sort(std::vector<int> &vec);
void	merge_sort(std::vector<int> &vec);

int	main(int argc, char **argv)
{
	// if (argc != 2)
	// 	return (1);
	
	std::vector<int>	c1;
	//std::stringstream	is(argv[1]);
	for (int i = 1; argv[i]; i++)
	{
		c1.push_back(std::atoi(argv[i]));
	}
	// if (is.bad()) // check for bad input?
	// 	std::__throw_invalid_argument("Invalid input.");
	// // insert_sort(c1);
	print_numbers(c1);
	std::cout << std::endl;
	mergeInsertSort(makeGroupIterator(c1.begin(), 2),
					makeGroupIterator(c1.end(), 2));
	//merge_sort(c1);
	std::cout << std::endl;
	return 0;
}

// void	insert_sort(std::vector<int> &vec)
// {
// 	for (int i = 0; i != vec.size(); i++)
// 	{
// 		for(int	j = 0; j != i; j++)
// 		{
// 			if (vec[i] < vec[j])
// 			{
// 				int	tmp = vec[i];
// 				vec.erase(vec.begin() + i);
// 				vec.insert(vec.begin() + j, tmp);
// 				break;
// 			}
// 		}
// 	}
// }

// void	merge_sort(std::vector<int> &vec)
// {
// 	if (vec.size() == 1)
// 	{
// 		std::cout << vec[0] << std::endl;
// 		return ;
// 	}
// 	int	mid = vec.size() / 2;
// 	std::cout << "mid is " << mid << std::endl;
// 	std::vector<int>	left(mid);
// 	std::vector<int>	right(vec.size() - mid);
// 	for(int i = 0; i < mid; i++)
// 		left.push_back(vec[i]);
// 	for(int i = mid; i < vec.size(); i++)
// 		right.push_back(vec[i]);
// 	std::cout << "left size " << left.size() << std::endl;
// 	print_numbers(left);
// 	merge_sort(left);
// 	std::cout << "to right" << std::endl;
// 	merge_sort(right);
// }
