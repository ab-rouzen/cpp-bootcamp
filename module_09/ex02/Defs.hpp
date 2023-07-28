#ifndef	DEFS_HPP
#define DEFS_HPP

#include "GroupIterator.hpp"

groupIterator<vec>	makeGroupIterator(groupIterator<vec> &it, std::size_t size);
groupIterator<vec>	makeGroupIterator(vecIt it, std::size_t size);
void				swap_iter(groupIterator<vec> begin, groupIterator<vec> end);
void				mergeInsertSort(groupIterator<vec> first, groupIterator<vec> last);

groupIterator<deq>	makeGroupIterator(groupIterator<deq> &it, std::size_t size);
groupIterator<deq>	makeGroupIterator(deqIt it, std::size_t size);
void				swap_iter(groupIterator<deq> begin, groupIterator<deq> end);
void				mergeInsertSort(groupIterator<deq> first, groupIterator<deq> last);

#endif // ! DEFS_HPP