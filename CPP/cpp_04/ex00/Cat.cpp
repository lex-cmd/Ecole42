#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Вызван cat конструктор" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Вызван cat деструктор" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Недовольную мурчание" << std::endl;
}
