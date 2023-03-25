#ifndef	SERIALIZER_H
#define	SERIALIZER_H
#include <stdint.h>

struct Data
{
	int		n;
	char	c;
};

class	Serializer{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
};

#endif // ! SERIALIZER_H