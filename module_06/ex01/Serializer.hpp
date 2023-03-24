#ifndef	SERIALIZER_H
#define	SERIALIZER_H
#include <MacTypes.h>

struct Data
{
	int		n;
	char	c;
};

//typedef unsigned int * uintptr_t;


class	Serializer{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
};

#endif // ! SERIALIZER_H