#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "Soap";
	std::cout << "ScavTrap default constructor called: " << name << std::endl;
	dmg = 20;
	energy = 50;
	hp = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called: " << name << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	std::cout << "ScavTrap constructor called: " << this->name << std::endl;
	dmg = 20;
	energy = 50;
	hp = 100;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target) 
{
	std::cout << "ScavTrap " << name << " attack " << target << ", causing " << dmg << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << name << " take " << amount << " points of damage" << std::endl;
	hp -= amount;
	if (hp < 0)
	{
		hp = 0;
		std::cout << "ScavTrap dead" << std::endl; 
	}
	std::cout << "ScavTrap " << name << " " << hp << " hp has been left" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << name << "was repaired, " << amount << "points was used" << std::endl;
	hp += amount;
	std::cout << "ScavTrap " << name << " " << hp << " hp has been left" << std::endl;
}
