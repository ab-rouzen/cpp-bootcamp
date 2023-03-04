#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &myName)
	: ClapTrap(myName)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
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
	name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	std::cout << "ScavTrap copy assignment operator has been called." << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << name << " attacks " << target;
	std::cout << ", causing " << attackDamage << " points of damage." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now gate keeper." << std::endl;
}