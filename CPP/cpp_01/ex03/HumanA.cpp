#include "HumanA.hpp"

HumanA::~HumanA()
{

}

HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon)
{
	this->name = name;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}
