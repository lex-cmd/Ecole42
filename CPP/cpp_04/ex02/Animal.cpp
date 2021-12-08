#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Вызван конструктор animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Вызван деструктор animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Вызван конструктор копирования animal" << std::endl;

	*this = other;
}

const std::string	Animal::getType() const
{
	return (type);
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Вызван оператор присваивания animal" << std::endl;

	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Animal &other)
{
	out << other.getType();
	return (out);
}
