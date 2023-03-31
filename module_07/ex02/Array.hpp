#ifndef	ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>
#include <iostream>

template<class T>
class Array
{
private:
	T				*ar;
	unsigned int	arraySize;

public:
	Array()
	{
		arraySize = 0;
		ar = new T[0]();
	};

	Array(unsigned int n)
	{
		arraySize = n;
		ar = new T[n]();
	};

	Array(const Array<T>& copy)
	{
		this->ar = 0;
		this->arraySize = 0;
		*this = copy;
	};

	Array<T>&	operator=(const Array<T>& copy)
	{
		if (this != &copy)
		{
			arraySize = copy.arraySize;
			delete [] ar;
			ar = new T[arraySize];
			for (unsigned int i = 0; i < arraySize; i++)
				ar[i] = copy.ar[i];
		}
		return (*this);
	};

	T&	operator[](unsigned int index)
	{
		if (index > arraySize - 1 || arraySize == 0)
			throw std::out_of_range("out of range");
		return(ar[index]);
	};

	const T&	operator[](unsigned int index) const
	{
		if (index > arraySize - 1 || arraySize == 0)
			throw std::out_of_range("out of range");
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