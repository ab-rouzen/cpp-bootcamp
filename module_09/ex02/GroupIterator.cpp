#include "GroupIterator.hpp"

/* =============== FOR DEQUE ================= */

groupIterator<deq>	makeGroupIterator(groupIterator<deq> &it, std::size_t size)
{
	return (groupIterator<deq>(it.base(), size * it.size()));
}

groupIterator<deq>	makeGroupIterator(deqIt it, std::size_t size)
{
	return (groupIterator<deq>(it, size));
}

/* =============== FOR VECTOR ================= */

groupIterator<vec>	makeGroupIterator(groupIterator<vec> &it, std::size_t size)
{
	return (groupIterator<vec>(it.base(), size * it.size()));
}

groupIterator<vec>	makeGroupIterator(vecIt it, std::size_t size)
{
	return (groupIterator<vec>(it, size));
}

