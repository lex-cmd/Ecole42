#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
{
	this->type = type;
	// std::cout << "String constructor for AMateria called" << std::endl;
	return;
}

const std::string &AMateria::getType() const //Returns the materia type
{
	return (this->type);
}

AMateria::~AMateria(){};

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
