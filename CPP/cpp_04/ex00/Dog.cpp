#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Вызван dog конструктор" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Вызван dog деструктор" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "ЯРОСТНЫЙ ЛАЙ" << std::endl;
}
