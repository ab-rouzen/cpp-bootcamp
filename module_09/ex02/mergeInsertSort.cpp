#include "GroupIterator.hpp"

groupIterator	makeGroupIterator(groupIterator &it, std::size_t size)
{
	return (groupIterator(it.base(), size * it.size()));
}

groupIterator	makeGroupIterator(vecIt it, std::size_t size)
{
	return (groupIterator(it, size));
}

void	swap_iter(groupIterator begin, groupIterator end)
{
	std::swap_ranges(begin.base(), begin.base() + begin.size(), end.base());
}

void	mergeInsertSort(groupIterator first, groupIterator last)
{
	size_t size = std::distance(first.base(), last.base());
	if (size < 2)
		return ;

	std::cout << first[0] << std::endl;
	std::cout << last[0] << std::endl;
	bool is_odd = (size % 2);
	is_odd ? last-- : last;
	for(groupIterator it = first; it != last; it = it + 2)
	{
		std::cout << it[0] << std::endl;
		std::cout << it[1] << std::endl;
		if(it[1] > it[0])
		{
			swap_iter(it, it + 1);
		}
	}
	mergeInsertSort(makeGroupIterator(first, 2),
					makeGroupIterator(last,  2));
	std::cout << "list of numbers here > ";
	for (; first != last; first++)
	{
		std::cout << first[0];
	}
	std::cout << std::endl; 
}
