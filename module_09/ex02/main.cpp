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
	if (argc < 2)
		return (1);
	std::vector<int>	c1;
	std::deque<int>		c2;
	for (int i = 1; argv[i]; i++){
		c1.push_back(std::atoi(argv[i]));
		c2.push_back(std::atoi(argv[i]));
	}
	print_numbers(c1);
	std::cout << std::endl;
	PmergeMe<std::vector<int> >	merge(c1);
	merge.sort();
	print_numbers(c1);
	std::cout << std::endl;
	
	std::cout << "==========" << std::endl;
	
	print_numbers(c2);
	std::cout << std::endl;
	PmergeMe<std::deque<int> >	merge2(c2);
	merge2.sort();
	print_numbers(c2);
	std::cout << std::endl;

	return 0;
}

