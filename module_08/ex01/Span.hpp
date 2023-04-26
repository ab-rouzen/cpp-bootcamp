#ifndef	SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	public:
		Span(unsigned int size);
		Span(const Span &copy);
		Span&	operator=(const Span &copy);
		~Span();
		void	addNumber(int number);
		void	addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
		int		shortestSpan(void);
		int		longestSpan(void) const;

	private:
		std::vector<int>	holder;
		int					insertCount;
		int					maxSize;
};

#endif // ! SPAN_HPP