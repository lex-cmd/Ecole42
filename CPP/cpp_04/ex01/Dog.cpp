#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Вызван конструктор dog" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Вызван деструктор dog" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Вызван конструктор копирования dog" << std::endl;
	this->type = other.type;

	if (other.brain)
	{
		this->brain = new Brain;
		this->brain = other.brain;
	}
}

Brain	*Dog::getBrain() const
{
	return(this->brain);
}

void	Dog::makeSound() const
{
	std::cout << "ЯРОСТНЫЙ ЛАЙ" << std::endl;
}

Dog		&Dog::operator=(const Dog &other)
{
	std::cout << "Вызван оператор присваивания dog" << std::endl;

	if (this == &other)
		return (*this);
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = 0;
	if (other.brain)
	{
		this->brain = new Brain;
		*(this->brain) = *(other.brain);
	}
	else
		this->brain = 0;
	return (*this);
}


Animal 		&Dog::operator=(const Animal &other)
{
	std::cout << "Вызван оператор присваивания animal dog" << std::endl;

	this->type = other.getType();
	*(this->brain) = *(other.getBrain());
	return (*this);
}
