#ifndef	ITER_HPP
#define ITER_HPP

template<class T>
void	iter(T *p, int lenght, void (*func) (T& elem))
{
	if ( p == 0 || func == 0)
		return;
	for (int i = 0; i < lenght; i++)
	{
		func(p[i]);
	}
}

#endif	// ! ITER_HPP