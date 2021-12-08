#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << status << " ClapTrap destructor called: " << name << std::endl;
}

ClapTrap::ClapTrap()
{
	status = "ClapTrap";
	name = "Salami Trap";
	std::cout << status << " default constructor called: " << name << std::endl;
	hp = 10;
	energy = 10;
	dmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	status = "ClapTrap";
	this->name = name;
	std::cout << status << " constructor called: " << name << std::endl;
	hp = 10;
	energy = 10;
	dmg = 0;
}

void ClapTrap::attack(std::string const &target) 
{
	std::cout << status << " " << name << " attack " << target << ", causing " << dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << status << " " << name << " take " << amount << " points of damage" << std::endl;
	hp -= amount;
	if (hp < 0)
	{
		hp = 0;
		std::cout << status << " dead" << std::endl; 
	}
	std::cout << status << " " << name << " " << hp << " hp has been left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << status << " " << name << "was repaired, " << amount << "points was used" << std::endl;
	hp += amount;
	std::cout << status << " " << name << " " << hp << " hp has been left" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

int		ClapTrap::getHP() const
{
	return (this->hp);
}

int		ClapTrap::getEnergy() const
{
	return (energy);
}

int		ClapTrap::getDmg() const
{
	return (dmg);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void	ClapTrap::setHP(int hp)
{
	this->hp = hp;
}

void	ClapTrap::setEnergy(int energy)
{
	this->energy = energy;
}

void	ClapTrap::setDmg(int dmg)
{
	this->dmg = dmg;
}
