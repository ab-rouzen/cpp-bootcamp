#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &myName)
	: ClapTrap(myName)
{
	std::cout << "ScavTrap constructor has been called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
	: ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor has been called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	(void) copy;
	std::cout << "ScavTrap copy assignment operator has been called." << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now gate keeper." << std::endl;
}