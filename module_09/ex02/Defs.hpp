#ifndef	DEFS_HPP
#define DEFS_HPP

#include "GroupIterator.hpp"

groupIterator	makeGroupIterator(groupIterator &it, std::size_t size);
groupIterator	makeGroupIterator(vecIt it, std::size_t size);
void			swap_iter(groupIterator begin, groupIterator end);
void			mergeInsertSort(groupIterator first, groupIterator last);

#endif // ! DEFS_HPP