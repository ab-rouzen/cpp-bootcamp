#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &myName)
	: ClapTrap(myName)
{
	std::cout << "FragTrap constructor has been called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
	: ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor has been called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	std::cout << "FragTrap copy assignment operator has been called." << std::endl;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap wants to have a positive high five..." << std::endl;
}
