#include "Span.hpp"

Span::Span(unsigned int size)
	: maxSize(size)
{
	insertCount = 0;
}

Span::Span(const Span &copy)
	: maxSize(copy.maxSize)
{
	insertCount = 0;
	holder = copy.holder;
}

Span&	Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		maxSize = copy.maxSize;
		holder = copy.holder;
		insertCount = copy.insertCount;
	}
	return (*this);
}

Span::~Span()	{}

void	Span::addNumber(int number)
{
	if (insertCount < maxSize)
	{
		holder.push_back(number);
		insertCount++;
		return ;
	}
	std::__throw_runtime_error("Max inserted elements surpassed.");
}

void	Span::addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	for (; first != last; first++)
	{
		addNumber(*first);
	}
}

int	Span::longestSpan(void) const
{
	std::vector<int>::const_iterator min = std::min_element(holder.begin(), holder.end());
	std::vector<int>::const_iterator max = std::max_element(holder.begin(), holder.end());
	return (*max - *min);
}

int	Span::shortestSpan(void) 
{
	if (insertCount < 2)
		std::__throw_runtime_error("Number of elements less than 2");
	std::sort(holder.begin(), holder.end());
	int	span = std::abs(holder[0] - holder[1]);
	for (int i = 0; i < insertCount - 1; i++)
	{
		int tmpSpan = std::abs(holder[i] - holder[i + 1]);
		if (span > tmpSpan)
			span = tmpSpan;
	}
	return (span);
}
