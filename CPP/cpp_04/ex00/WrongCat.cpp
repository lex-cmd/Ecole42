#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "Вызван конструктор WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Вызван деструктор WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Недовольное жмурчание" << std::endl;
}
