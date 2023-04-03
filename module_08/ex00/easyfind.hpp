#ifndef	EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>

template<class T>
const int&	easyfind(const T& x, int n){
	typename T::const_iterator	itVal;
	itVal = std::find(x.begin(), x.end(), n);
	if (itVal == x.end())
		throw	std::runtime_error("element not found");
	return (*itVal);
}

#endif	// ! EASYFIND_HPP