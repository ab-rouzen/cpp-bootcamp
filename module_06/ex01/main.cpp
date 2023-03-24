#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	data;
	Data*	pdata = &data;
	data.c = 'b';
	data.n = 37;

	uintptr_t	ptr = Serializer::serialize(&data);
	Data*	sdata = Serializer::deserialize(ptr);
	std::cout << std::boolalpha << (pdata == sdata) << std::endl;
	std::cout << sdata->c << std::endl;
	std::cout << sdata->n << std::endl;
	return 0;
}