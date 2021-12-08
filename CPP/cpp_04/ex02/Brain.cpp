#include "Brain.hpp"

Brain::Brain()
{
	// std::cout << "Вызван конструктор brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	// std::cout << "Вызван конструктор копирования Brain" << std::endl;

	*this = other;
}

Brain::~Brain()
{
	// std::cout << "Вызван деструктор brain" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	// std::cout << "Вызван оператор присваивания Brain" << std::endl;

	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}
