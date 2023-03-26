#ifndef	WHATEVER_H
#define WHATEVER_H

template<class T>
void	swap(T& v1, T&	v2)
{
	T	tmp = v1;
	v1 = v2;
	v2 = tmp;
}

template<class T>
const T&	min(const T& v1, const T& v2)
{
	if (v1 < v2)
		return	(v1);
	return (v2);
}

template<class T>
const T&	max(const T& v1, const T& v2)
{
	if (v2 >= v1)
		return (v2);
	return (v1);
}

#endif	// ! WHATEVER_H