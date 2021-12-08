#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	status = "FragTrap";
	this->name = "cocoa";
	hp = 100;
	energy = 100;
	dmg = 30;
	std::cout << status << " default constructor called: " << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << status << " destructor called: " << name << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	status = "FragTrap";
	this->name = name;
	std::cout << status << " constructor called: " << name << std::endl;
	hp = 100;
	energy = 100;
	dmg = 30;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << status << " high Fives guys: " << name << std::endl;
}
