#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{	
	this->type = "WrongAnimal";
	std::cout << "Вызван конструктор WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Вызван деструктор WrongAnimal" << std::endl;
}

void			WrongAnimal::makeSound() const
{
	std::cout << "Животный стон" << std::endl;
}

std::string		WrongAnimal::getType() const
{
	return (type);
}

void			WrongAnimal::setType(std::string type)
{
	this->type = type;
}
