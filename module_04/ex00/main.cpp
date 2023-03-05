#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal boot;
	Cat		tom;
	Dog		hat;
	

	boot.makeSound();
	tom.makeSound();
	hat.makeSound();
	return 0;
}