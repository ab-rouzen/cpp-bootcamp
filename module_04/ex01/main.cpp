#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal	*myCat = new Cat();
	const Animal	*myDog = new Dog();

	delete myCat;
	delete myDog;
	return 0;
}