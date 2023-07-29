#ifndef GROUP_ITERATOR_HPP
#define GROUP_ITERATOR_HPP

#include<algorithm>
#include<iterator>
#include<iostream>
#include<vector>
#include<deque>

typedef	std::vector<int> vec;
typedef	std::vector<int>::iterator vecIt;
typedef	std::deque<int> deq;
typedef	std::deque<int>::iterator deqIt;

template<typename C>
class	groupIterator
{
	public:
 
		typedef	C&	reference;
		typedef	typename C::iterator iterator_type;
	
		groupIterator(iterator_type it, std::size_t size)
			: _it(it), _size(size)
		{}
		~groupIterator()
		{}
		groupIterator(const groupIterator &copy)
		{
			this->_it = copy._it;
			this->_size = copy._size;
		}
		groupIterator&	operator=(const groupIterator &copy)
		{
			if (this != &copy)
			{
				this->_it = copy._it;
				this->_size = copy._size;
			}
			return (*this);
		}
		iterator_type&	base()
		{
			return (_it);
		}
		std::size_t	size()
		{
			return (_size);
		}
		
	// operators:
		int				operator[](std::size_t index)
		{
			return (_it[_size * index + _size - 1]); // get last element, largest.
		}
		iterator_type	operator()(std::size_t index)
		{
			return (_it + _size * index + _size);
		}
		groupIterator&	operator+=(std::size_t step)
		{
			_it += step * _size;
			return (*this);
		}
		groupIterator	operator+(std::size_t step)
		{
			return (groupIterator(_it + step * _size, _size));
		}
		groupIterator&	operator-=(std::size_t step)
		{
			_it -= step * _size;
			return (*this);
		}
		int				operator-(groupIterator &rhs)
		{
			return (((*this).base() - rhs.base()) / _size);
		}
		groupIterator&	operator++(int)
		{
			_it += _size;
			return (*this);
		}
		groupIterator&	operator--(int)
		{
			_it -= _size;
			return (*this);
		}
		bool			operator!=(groupIterator &rhs)
		{
			return (this->base() != rhs.base());
		}
		bool			operator==(groupIterator &rhs)
		{
			return (this->base() == rhs.base());
		}
		bool			operator==(int rhs)
		{
			return (*(this->base()) == rhs);
		}
		bool			operator<(groupIterator &rhs)
		{
			*this < *rhs;
		}
		int				operator*()
		{
			return (_it[_size - 1]);
		}


	private:
		iterator_type		_it;
		std::size_t			_size;

		groupIterator() {};
};

template<typename T>
bool	cmp(T first, T second)
{
	return (first[0] < second[0]);
}

// create a new groupIterator objet from argument iterator and size
groupIterator<vec>	makeGroupIterator(groupIterator<vec> &it, std::size_t size);
groupIterator<vec>	makeGroupIterator(vecIt it, std::size_t size);
groupIterator<deq>	makeGroupIterator(groupIterator<deq> &it, std::size_t size);
groupIterator<deq>	makeGroupIterator(deqIt it, std::size_t size);

#endif	// ! GROUP_ITERATOR