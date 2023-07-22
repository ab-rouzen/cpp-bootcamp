#ifndef GROUP_ITERATOR_HPP
#define  GROUP_ITERATOR_HPP

#include<algorithm>
#include<iterator>
#include<iostream>
#include<vector>

typedef	std::vector<int>::iterator vecIt;

class	groupIterator
{
	public:
		groupIterator(vecIt it, std::size_t size);
		~groupIterator();
		vecIt&	base();
		std::size_t	size();
		
	// operators:
		int				operator[](std::size_t index);
		vecIt			operator()(std::size_t index);
		groupIterator&	operator+=(std::size_t step);
		groupIterator	operator+(std::size_t step);
		groupIterator&	operator-=(std::size_t step);
		int				operator-(groupIterator &rhs);
		groupIterator&	operator++(int);
		groupIterator&	operator--(int);
		bool			operator!=(groupIterator &rhs);
		bool			operator==(groupIterator &rhs);


	private:
		vecIt		_it;
		std::size_t	_size;

		groupIterator() {};
};

#endif	// ! GROUP_ITERATOR