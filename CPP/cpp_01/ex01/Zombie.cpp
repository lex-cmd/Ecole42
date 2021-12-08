#include "Zombie.hpp"

void	Zombie::SetName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	this->name = "random name";
}

Zombie::~Zombie()
{
	std::cout << "destructor called " << this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
