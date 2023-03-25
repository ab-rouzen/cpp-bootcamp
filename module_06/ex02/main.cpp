#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify(Base*);
void	identify(Base&);
Base*	generate(void);

int	main(void)
{
	srand(time(NULL));
	Base	&bref = *generate();
	identify(bref);
	Base	*ptr = generate();
	identify(ptr);
}
