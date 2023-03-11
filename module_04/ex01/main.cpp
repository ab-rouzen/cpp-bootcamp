#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal*	Anim[64];
	for (int i = 0; i < 64; i++)
	{
		if (i % 2)
			Anim[i] = new Cat();
		else
			Anim[i] = new Dog();
	}
	for (int i = 0; i < 64; i++)
		delete Anim[i];
	return 0;
}