#include "PmergeMe.hpp"
#include "GroupIterator.hpp"
#include "Defs.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <utility>

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

	std::vector<int>		c1;
	std::deque<int>			c2;
	std::map<int, char>		m;

	for (int i = 1; argv[i]; i++){
		int val = std::atoi(argv[i]);
		c1.push_back(val);
		c2.push_back(val);
		if (m.insert(std::make_pair(val, 'c')).second == false)
		{
			std::cout << "duplicate values found." << std::endl;
			return (1);
		}
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

