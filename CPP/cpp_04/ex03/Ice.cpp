#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Вызван конструктор ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	// std::cout << "Вызван конструктор ice" << std::endl;
	*this = other;
}

Ice::~Ice()
{
	// std::cout << "Вызван деструктор ice" << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

std::string const &Ice::getType() const
{
	return (this->type);
}

Ice &Ice::operator=(const Ice &other)
{
	this->type = other.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Ice &other)
{
	out << other.getType();
	return (out);
}
