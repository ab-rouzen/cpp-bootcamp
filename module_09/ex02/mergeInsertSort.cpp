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

void	binaryInsert(std::vector<int> &vec, groupIterator start, groupIterator	end, groupIterator elem)
{
	int	mid = (end - start) / 2;
	if (start == end)
	{
		if (elem[0] > start[0])
			vec.insert((start + 1).base(), elem.base(), elem.base() + elem.size());
		else
			vec.insert(start.base(), elem.base(), elem.base() + elem.size());
		return;
	}
	if (elem[0] > start[mid])
		binaryInsert(vec, makeGroupIterator(start(mid), start.size()), end, elem);
	else
		binaryInsert(vec, start, makeGroupIterator(start(mid), start.size()), elem);

}

void	mergeInsertSort(groupIterator first, groupIterator last)
{
	// maxing at 3000 numbers sorted
	int	jbs_numbers[] = {3, 5, 11, 21, 43, 85, 170, 341, 683, 1365, 2731, 5461};
	size_t size = last - first;
	int	itLevel = first.size();
	if (size < 2)
		return ;

	// std::cout << first[0] << std::endl;
	// std::cout << last[0] << std::endl;
	bool is_odd = (size % 2);
	is_odd ? last-- : last;
	for(groupIterator it = first; it != last; it += 2)
	{
		std::cout << it[0] << std::endl;
		std::cout << it[1] << std::endl;
		if(it[1] < it[0])
		{
			swap_iter(it, it + 1);
		}
	}
	mergeInsertSort(makeGroupIterator(first, 2),
					makeGroupIterator(last,  2));
	// std::cout << "list of numbers here > ";
	// for (; first != last; first++)
	// {
	// 	std::cout << first[0];
	// }
	// std::cout << std::endl;
	// create main chain and pend.
	struct node
	{
		groupIterator	elem;
		int				mainPair;
	};
	
	std::vector<groupIterator>	main;
	std::vector<node>			pend;
	for(groupIterator it = first; it != last; it += 2)
	{
		pend.push_back((node){it, *(it + 1)});
		main.push_back(it + 1);
	}
	std::cout << "main size: " << main.size() << std::endl;
	std::cout << "pend size: " << pend.size() << std::endl;

	std::vector<node>::iterator	pendfirst = pend.begin();
	//groupIterator	mainIte = makeGroupIterator(main.end(), first.size());

	// insert second element of first pair into the main chain always
	main.insert(main.begin(), (*pendfirst).elem);
	int	lastInsertedElem = 1;
	for(int i = 0;; i++)
	{
		int	ji = jbs_numbers[i] - 1;
		if (ji >= size / 2)
			ji = size / 2 - 1;
		for (int j = ji; j >= lastInsertedElem; j--)
		{
			//binaryInsert(main, makeGroupIterator(main.begin(), itLevel), makeGroupIterator(main.end(), itLevel), pendItb + i);
			std::vector<groupIterator>::iterator tmpEnd = std::find(main.begin(), main.end(), pend[j].mainPair);
			std::vector<groupIterator>::iterator insertPos = \
			std::upper_bound(main.begin(), tmpEnd, pend[j].elem, cmp);
			main.insert(insertPos, pend[j].elem);
		}
		lastInsertedElem = ji + 1;
		if (ji == size / 2 - 1)
			break;
	}

	// insert straggle element
	if (is_odd)
	{
	std::vector<groupIterator>::iterator insertPos = \
	std::upper_bound(main.begin(), main.end(), last, cmp);
	main.insert(insertPos, last);
	}

	std::vector<int>	tmp;
	for (std::vector<groupIterator>::iterator mainIt = main.begin(); mainIt != main.end(); mainIt++)
	{
		vecIt	begin = (*mainIt).base();
		vecIt	end = begin + (*mainIt).size();
		std::move(begin, end, std::back_inserter(tmp));
	}
	std::move(tmp.begin(), tmp.end(), first.base());
	//
}
