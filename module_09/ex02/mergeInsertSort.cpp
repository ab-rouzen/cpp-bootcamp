#include "GroupIterator.hpp"
#include "mergeInsertSort.hpp"

/* =============== FOR VECTOR ================= */

void	swap_iter(groupIterator<vec> begin, groupIterator<vec> end)
{
	std::swap_ranges(begin.base(), begin.base() + begin.size(), end.base());
}

// Sort elements using the Ford-Johnson merge insertion algorithm
// groupIterator is class that helps to treat a sequence in groups of elements, handle pairs in recursion and move them around
void	mergeInsertSort(groupIterator<vec> first, groupIterator<vec> last)
{
	// maxing at 3000 numbers sorted - chached array of jacobsthal numbers
	int	jbs_numbers[] = {3, 5, 11, 21, 43, 85, 170, 341, 683, 1365, 2731, 5461};
	int size = last - first;
	if (size < 2)
		return ;

	// removing last element from list if sequence is odd.
	bool is_odd = (size % 2);
	is_odd ? last-- : last;
	
	// traverse list as pairs, and sort each by smallest
	for(groupIterator<vec> it = first; it != last; it += 2){
		if(it[1] < it[0]){
			swap_iter(it, it + 1);
		}
	}

	// recursively merge insert resulting sequence of largest pairs
	mergeInsertSort(makeGroupIterator(first, 2),\
					makeGroupIterator(last,  2));

	// separate main chain and pend into different sequences
	std::vector<groupIterator<vec> >	main;
	std::vector<vNode>			pend;
	for(groupIterator<vec> it = first; it != last; it += 2){
		pend.push_back((vNode){it, *(it + 1)});
		main.push_back(it + 1);
	}

	// insert second element of first pair from pend into the main chain, always.
	std::vector<vNode>::iterator	pendfirst = pend.begin();
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
			std::vector<groupIterator<vec> >::iterator tmpEnd = std::find(main.begin(), main.end(), pend[j].mainPair);
			std::vector<groupIterator<vec> >::iterator insertPos = \
			std::upper_bound(main.begin(), tmpEnd, pend[j].elem, cmp<groupIterator<vec> >);
			main.insert(insertPos, pend[j].elem);
		}
		lastInsertedElem = ji + 1;
		if (ji == size / 2 - 1)
			break;
	}

	// insert odd element is present
	if (is_odd){
		std::vector<groupIterator<vec> >::iterator insertPos = \
		std::upper_bound(main.begin(), main.end(), last, cmp<groupIterator<vec> >);
		main.insert(insertPos, last);
	}

	// create a temporary sequence for holding the sorted list and then move into input sequence
	std::vector<int>	tmp;
	for (std::vector<groupIterator<vec> >::iterator mainIt = main.begin(); mainIt != main.end(); mainIt++)
	{
		vecIt	begin = (*mainIt).base();
		vecIt	end = begin + (*mainIt).size();
		std::move(begin, end, std::back_inserter(tmp));
	}
	std::move(tmp.begin(), tmp.end(), first.base());
}


/* =============== FOR DEQUE ================= */

void	swap_iter(groupIterator<deq> begin, groupIterator<deq> end)
{
	std::swap_ranges(begin.base(), begin.base() + begin.size(), end.base());
}

// Sort elements using the Ford-Johnson merge insertion algorithm
// groupIterator is class that helps to treat a sequence in groups of elements, handle pairs in recursion and move them around
void	mergeInsertSort(groupIterator<deq> first, groupIterator<deq> last)
{
	// maxing at 3000 numbers sorted - chached array of jacobsthal numbers
	int	jbs_numbers[] = {3, 5, 11, 21, 43, 85, 170, 341, 683, 1365, 2731, 5461};
	int size = last - first;
	if (size < 2)
		return ;

	// removing last element from list if sequence is odd.
	bool is_odd = (size % 2);
	is_odd ? last-- : last;
	
	// traverse list as pairs, and sort each by smallest
	for(groupIterator<deq> it = first; it != last; it += 2){
		if(it[1] < it[0]){
			swap_iter(it, it + 1);
		}
	}

	// recursively merge insert resulting sequence of largest pairs
	mergeInsertSort(makeGroupIterator(first, 2),\
					makeGroupIterator(last,  2));

	// separate main chain and pend into different sequences
	std::deque<groupIterator<deq> >	main;
	std::deque<dNode>			pend;
	for(groupIterator<deq> it = first; it != last; it += 2){
		pend.push_back((dNode){it, *(it + 1)});
		main.push_back(it + 1);
	}

	// insert second element of first pair from pend into the main chain, always.
	std::deque<dNode>::iterator	pendfirst = pend.begin();
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
			std::deque<groupIterator<deq> >::iterator tmpEnd = std::find(main.begin(), main.end(), pend[j].mainPair);
			std::deque<groupIterator<deq> >::iterator insertPos = \
			std::upper_bound(main.begin(), tmpEnd, pend[j].elem, cmp<groupIterator<deq> >);
			main.insert(insertPos, pend[j].elem);
		}
		lastInsertedElem = ji + 1;
		if (ji == size / 2 - 1)
			break;
	}

	// insert odd element if present
	if (is_odd){
		std::deque<groupIterator<deq> >::iterator insertPos = \
		std::upper_bound(main.begin(), main.end(), last, cmp<groupIterator<deq> >);
		main.insert(insertPos, last);
	}

	// create a temporary sequence for holding the sorted list and then move into input sequence
	std::deque<int>	tmp;
	for (std::deque<groupIterator<deq> >::iterator mainIt = main.begin(); mainIt != main.end(); mainIt++)
	{
		deqIt	begin = (*mainIt).base();
		deqIt	end = begin + (*mainIt).size();
		std::move(begin, end, std::back_inserter(tmp));
	}
	std::move(tmp.begin(), tmp.end(), first.base());
}
