#ifndef MERGE_INSERT_SORT_HPP
#define MERGE_INSERT_SORT_HPP

#include "GroupIterator.hpp"

// need this struct to keep track of corresponding main chain elements for pend
struct vNode
{
	groupIterator<vec>	elem;
	int					mainPair;
};

struct dNode
{
	groupIterator<deq>	elem;
	int					mainPair;
};


#endif	// ! MERGE_INSERTION_SORT_HPP