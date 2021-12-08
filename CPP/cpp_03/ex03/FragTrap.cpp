#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "cocoa";
	std::cout << "FragTrap default constructor called: " << name << std::endl;
	hp = 100;
	energy = 100;
	dmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called: " << name << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	std::cout << "FragTrap constructor called: " << name << std::endl;
	hp = 100;
	energy = 100;
	dmg = 30;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap high Fives guys: " << name << std::endl;
}

void FragTrap::attack(std::string const &target) 
{
	std::cout << "FragTrap " << name << " attack " << target << ", causing " << dmg << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << name << " take " << amount << " points of damage" << std::endl;
	hp -= amount;
	if (hp < 0)
	{
		hp = 0;
		std::cout << "FragTrap dead" << std::endl; 
	}
	std::cout << "FragTrap " << name << " " << hp << " hp has been left" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap " << name << "was repaired, " << amount << "points was used" << std::endl;
	hp += amount;
	std::cout << "FragTrap " << name << " " << hp << " hp has been left" << std::endl;
}
