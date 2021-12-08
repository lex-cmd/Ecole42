#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "Soap";
	status = "ScavTrap";
	std::cout << status << " default constructor called: " << name << std::endl;
	dmg = 20;
	energy = 50;
	hp = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << status << " destructor called: " << name << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	status = "ScavTrap";
	std::cout << status << " constructor called: " << this->name << std::endl;
	dmg = 20;
	energy = 50;
	hp = 100;
}

void ScavTrap::guardGate()
{
	std::cout << status << " " << name << " have enterred in Gate keeper mode" << std::endl;
}
