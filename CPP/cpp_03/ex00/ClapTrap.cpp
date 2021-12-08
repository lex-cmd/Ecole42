#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called: " << name << std::endl;
}

ClapTrap::ClapTrap()
{
	name = "Salami Trap";
	std::cout << "default constructor called: " << name << std::endl;
	hp = 10;
	energy = 10;
	dmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	std::cout << "constructor called: " << name << std::endl;
	hp = 10;
	energy = 10;
	dmg = 0;
}

void ClapTrap::attack(std::string const &target) 
{
	std::cout << "ClapTrap " << name << " attack " << target << ", causing " << dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " take " << amount << " points of damage" << std::endl;
	hp -= amount;
	if (hp < 0)
	{
		hp = 0;
		std::cout << "ClapTrap dead" << std::endl; 
	}
	std::cout << "ClapTrap " << name << " " << hp << " hp has been left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << "was repaired, " << amount << "points was used" << std::endl;
	hp += amount;
	std::cout << "ClapTrap " << name << " " << hp << " hp has been left" << std::endl;
}
