#ifndef	ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <stdexcept>

template<class T>
class Array
{
private:
	T				*ar;
	unsigned int	arraySize;
public:
	Array()
	{
		ar = 0;
		arraySize = 0;
	};

	Array(unsigned int n)
	{
		arraySize = n;
		ar = new T[n]();
	};

	Array(const Array<T>& copy)
	{
		arraySize = copy.arraySize;
		ar = new T[arraySize];
		for (int i = 0; i < arraySize; i++)
			ar[i] = copy.ar[i];
	};

	Array<T>&	operator=(const Array<T>& copy)
	{
		if (this != &copy)
		{
			arraySize = copy.arraySize;
			ar = new T[arraySize];
			for (int i = 0; i < arraySize; i++)
				ar[i] = copy.ar[i];
		}
		return (*this);
	};

	T&	operator[](unsigned int index)
	{
		if (index > arraySize - 1 || arraySize == 0)
			throw std::out_of_range("std");
		return(ar[index]);
	};

	unsigned int	size(void) const
	{
		return (arraySize);
	};

	~Array()
	{
		delete[] ar;
	};
};


#endif // ! ARRAY_HPP