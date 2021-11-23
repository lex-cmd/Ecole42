#include "HumanB.hpp"

HumanB::~HumanB()
{

}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = 0;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
