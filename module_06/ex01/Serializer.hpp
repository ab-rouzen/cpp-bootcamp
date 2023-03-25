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
		Serializer();
		Serializer(const Serializer &copy);
		Serializer&	operator=(const Serializer &copy);
		~Serializer();
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
};

#endif // ! SERIALIZER_H