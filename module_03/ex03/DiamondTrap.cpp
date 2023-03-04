#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &myName)
	: ClapTrap(myName + "_clap_name"), ScavTrap(myName), FragTrap(myName)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor has been called." << std::endl;
	name = myName;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	name = copy.name;
	std::cout << "DiamondTrap copy constructor has been called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		name = copy.name;
		ClapTrap::name = copy.ClapTrap::name;
		hitPoints = copy.hitPoints;
		energyPoints = copy.energyPoints;
		attackDamage = copy.attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << name << ", a diamond trap." << std::endl;
	std::cout << "My clap trap grand-parent's name is " << ClapTrap::name << std::endl;
}
