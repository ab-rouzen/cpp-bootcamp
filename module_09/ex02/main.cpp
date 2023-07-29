#include "PmergeMe.hpp"
#include "GroupIterator.hpp"
#include "Defs.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <sys/time.h>

template<class C>
void	print_numbers(C container_type)
{
	typename C::const_iterator	itb = container_type.begin();	
	typename C::const_iterator	ite = container_type.end();
	for (; itb != ite; itb++)
		std::cout << *itb << " ";
}

/*returns time difference in microseconds*/
long	getDiffTime(struct timeval *t0, struct timeval *t1)
{
	long diffSeconds = t1->tv_sec - t0->tv_sec;
	long diffMicroSeconds = diffSeconds * 1000000 + t1->tv_usec - t0->tv_usec;
	return (diffMicroSeconds);
}

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
		if (m.insert(std::make_pair(val, 'c')).second == false || val < 0)
		{
			std::cout << "duplicate or negative values found." << std::endl;
			return (1);
		}
	}
	struct timeval lapse[4];
	std::cout << "Before : ";
	print_numbers(c1);
	std::cout << std::endl;
	PmergeMe<std::vector<int> >	merge(c1);
	gettimeofday(&lapse[0], NULL);
	merge.sort();
	gettimeofday(&lapse[1], NULL);
	std::cout << "After  : ";
	print_numbers(c1);
	std::cout << std::endl;
	PmergeMe<std::deque<int> >	merge2(c2);
	gettimeofday(&lapse[2], NULL);
	merge2.sort();
	gettimeofday(&lapse[3], NULL);
	std::cout  <<  "time elpased processing sequence for std::vector: "<< getDiffTime(&lapse[0], &lapse[1]) << " us" << std::endl; 
	std::cout  <<  "time elpased processing sequence for std::deque	: "<< getDiffTime(&lapse[2], &lapse[3]) << " us" << std::endl; 
	return 0;
}

