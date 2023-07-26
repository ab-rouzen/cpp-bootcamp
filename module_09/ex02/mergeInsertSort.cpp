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

// Sort elements using the Ford-Johnson merge insertion algorithm
// groupIterator is class that helps to treat a sequence in groups of elements, handle pairs in recursion and move them around
void	mergeInsertSort(groupIterator first, groupIterator last)
{
	// maxing at 3000 numbers sorted - chached array of jacobsthal numbers
	int	jbs_numbers[] = {3, 5, 11, 21, 43, 85, 170, 341, 683, 1365, 2731, 5461};
	size_t size = last - first;
	if (size < 2)
		return ;

	// removing last element from list if sequence is odd.
	bool is_odd = (size % 2);
	is_odd ? last-- : last;
	
	// traverse list as pairs, and sort each by smallest
	for(groupIterator it = first; it != last; it += 2){
		if(it[1] < it[0]){
			swap_iter(it, it + 1);
		}
	}

	// recursively merge insert resulting sequence of largest pairs
	mergeInsertSort(makeGroupIterator(first, 2),\
					makeGroupIterator(last,  2));
	
	// need this struct to keep track of corresponding main chain elements for pend
	struct node
	{
		groupIterator	elem;
		int				mainPair;
	};

	// separate main chain and pend into different sequences
	std::vector<groupIterator>	main;
	std::vector<node>			pend;
	for(groupIterator it = first; it != last; it += 2){
		pend.push_back((node){it, *(it + 1)});
		main.push_back(it + 1);
	}

	// insert second element of first pair from pend into the main chain, always.
	std::vector<node>::iterator	pendfirst = pend.begin();
	main.insert(main.begin(), (*pendfirst).elem);
	int	lastInsertedElem = 1;
	
	// insert other pend elements into the main chain following jacobsthal numbers - it works!
	for(int i = 0;; i++)
	{
		int	ji = jbs_numbers[i] - 1;
		if (ji >= size / 2)
			ji = size / 2 - 1;
		for (int j = ji; j >= lastInsertedElem; j--)
		{
			std::vector<groupIterator>::iterator tmpEnd = std::find(main.begin(), main.end(), pend[j].mainPair);
			std::vector<groupIterator>::iterator insertPos = \
			std::upper_bound(main.begin(), tmpEnd, pend[j].elem, cmp);
			main.insert(insertPos, pend[j].elem);
		}
		lastInsertedElem = ji + 1;
		if (ji == size / 2 - 1)
			break;
	}

	// insert odd element is present
	if (is_odd){
		std::vector<groupIterator>::iterator insertPos = \
		std::upper_bound(main.begin(), main.end(), last, cmp);
		main.insert(insertPos, last);
	}

	// create a temporary sequence for holding the sorted list and then move into input sequence
	std::vector<int>	tmp;
	for (std::vector<groupIterator>::iterator mainIt = main.begin(); mainIt != main.end(); mainIt++)
	{
		vecIt	begin = (*mainIt).base();
		vecIt	end = begin + (*mainIt).size();
		std::move(begin, end, std::back_inserter(tmp));
	}
	std::move(tmp.begin(), tmp.end(), first.base());
}
