#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &myName)
	: name(myName), hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "ClapTrap constructor has been called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy assignment operator has been called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		hitPoints -= amount;
		if (hitPoints < 0)
			hitPoints = 0;
		std::cout << "ClapTrap " << name << " has taken " << amount;
		std::cout << " points of damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " has gained " << amount;
		std::cout << " hit points." << std::endl;
		hitPoints += amount;
	}
}