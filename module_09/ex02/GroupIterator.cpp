#include "GroupIterator.hpp"

groupIterator::groupIterator(vecIt it, std::size_t size)
	: _it(it), _size(size)
{}

// groupIterator::groupIterator(groupIterator &copy)
// {
// 	this->_it = copy._it;
// 	this->_size = copy._size;
// }

groupIterator::groupIterator(const groupIterator &copy)
{
	this->_it = copy._it;
	this->_size = copy._size;
}

groupIterator &groupIterator::operator=(const groupIterator &copy)
{
	if (this != &copy)
	{
		this->_it = copy._it;
		this->_size = copy._size;
	}
	return (*this);
}

groupIterator::~groupIterator()
{}

int	groupIterator::operator[](std::size_t index)
{
	return (_it[_size * index + _size - 1]); // get last element, largest.
}
vecIt	groupIterator::operator()(std::size_t index)
{
	return (_it + _size * index + _size);
}

vecIt&	groupIterator::base()
{
	return (_it);
}

std::size_t	groupIterator::size()
{
	return (_size);
}

/* CLASS OPERATORS */

groupIterator&	groupIterator::operator-=(std::size_t step)
{
	_it -= step * _size;
	return (*this);
}

int	groupIterator::operator-(groupIterator &rhs)
{
	return (((*this).base() - rhs.base()) / _size);
}

groupIterator&	groupIterator::operator+=(std::size_t step)
{
	_it += step * _size;
	return (*this);
}

groupIterator	groupIterator::operator+(std::size_t step)
{
	return (groupIterator(_it + step * _size, _size));
}

groupIterator&	groupIterator::operator++(int)
{
	_it += _size;
	return (*this);
}

groupIterator&	groupIterator::operator--(int)
{
	_it -= _size;
	return (*this);
}

bool	groupIterator::operator!=(groupIterator &rhs)
{
	return (this->base() != rhs.base());
}

bool	groupIterator::operator==(groupIterator &rhs)
{
	return (this->base() == rhs.base());
}

bool	groupIterator::operator==(int rhs)
{
	return (*(this->base()) == rhs);
}

int	groupIterator::operator*()
{
	return (_it[_size - 1]);
}

bool	cmp(groupIterator first, groupIterator second)
{
	return (first[0] < second[0]);
}