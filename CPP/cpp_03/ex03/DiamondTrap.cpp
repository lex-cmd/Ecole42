#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap():ClapTrap()
{
	std::cout << "DiamondTrap default constructor called: " << name << std::endl;
	ClapTrap::name = "_clap_name";
	ClapTrap::name = "Hot chocolate" + ClapTrap::name;
	name = "Hot chocolate";
	hp = FragTrap::hp;
	energy = ScavTrap::energy;
	dmg = FragTrap::dmg;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor called: " << name << std::endl;
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	hp = FragTrap::hp;
	energy = ScavTrap::energy;
	dmg = FragTrap::dmg;
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is " << name << " | clapTrap name is "<< ClapTrap::name << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
