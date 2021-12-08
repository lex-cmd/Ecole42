#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Вызван animal конструктор" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Вызван animal  деструктор" << std::endl;
}

void		Animal::makeSound() const
{
	std::cout << "Животный лай" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}

void		Animal::setType(std::string type)
{
	this->type = type;
}
