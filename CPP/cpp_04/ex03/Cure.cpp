#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Вызван конструктор cure" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	// std::cout << "Вызван конструктор cure" << std::endl;
	*this = other;
}

Cure::~Cure()
{
	// std::cout << "Вызван деструктор cure" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << target.getName() << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

std::string const &Cure::getType() const
{
	return (this->type);
}

Cure &Cure::operator=(const Cure &other)
{
	this->type = other.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Cure &other)
{
	out << other.getType();
	return (out);
}

