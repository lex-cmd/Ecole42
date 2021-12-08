#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Вызван конструктор cat" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Вызван конструктор копирования cat" << std::endl;

	this->type = other.type;

	if (other.brain)
	{
		this->brain = new Brain;
		this->brain = other.brain;
	}
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Вызван деструктор cat" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Недовольную мурчание" << std::endl;
}

Brain	*Cat::getBrain( void ) const
{
	return (this->brain);
}


Cat		&Cat::operator=(const Cat &other)
{
	std::cout << "Вызван оператор присваивания cat" << std::endl;

	if (this == &other)
		return (*this);
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	if (other.brain)
	{
		this->brain = new Brain;
		*(this->brain) = *(other.brain);
	}
	else
		brain = 0;
	return (*this);
}


Animal 		&Cat::operator=(const Animal &other)
{
	std::cout << "Вызван оператор присваивания animal cat" << std::endl;

	this->type = other.getType();
	*(this->brain) = *(other.getBrain());
	return (*this);
}
