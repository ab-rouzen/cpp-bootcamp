#include <iostream>
#include "Span.hpp"

int	main()
{
	Span				foo(10020);
	std::vector<int>	bar;

	foo.addNumber(6);
	foo.addNumber(3);
	foo.addNumber(17);
	foo.addNumber(9);
	foo.addNumber(11);
	for (int i = 0; i <= 10000; i++)
	{
		foo.addNumber(i);
	}
	std::cout << foo.longestSpan() << std::endl;
	std::cout << foo.shortestSpan() << std::endl;
	
	std::cout << std::endl << "/*****************/" << std::endl << std::endl;
	
	bar.push_back(7);
	bar.push_back(9);
	bar.push_back(-3);
	Span iter(3);
	iter.addNumber(bar.begin(), bar.end());
	bar.insert(bar.begin(), bar.begin(), bar.end());
	std::cout << iter.shortestSpan() << std::endl;
	std::cout << iter.longestSpan() << std::endl;
	//iter.addNumber(4);
	return (0);
}
