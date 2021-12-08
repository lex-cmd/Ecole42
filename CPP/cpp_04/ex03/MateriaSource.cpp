#include "MateriaSource.hpp"

MateriaSource::~MateriaSource()
{
	// std::cout << "Вызван деструктор MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	// std::cout << "Вызван конструктор MateriaSource" << std::endl;
	this->index_mat = other.index_mat;
	for (int i = 0; i < NUMOFMAT; i++)
	{
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = 0;
	}
}

MateriaSource::MateriaSource()
{
	// std::cout << "Вызван конструктор MateriaSource" << std::endl;
	index_mat = 0;
	for (int i = 0; i < NUMOFMAT; i++)
		materias[i] = 0;
}

void MateriaSource::learnMateria(AMateria *other)
{
	if (index_mat >= NUMOFMAT)
		std::cout << "Закончились свободные ячейки" << std::endl;
	else
	{
		materias[index_mat] = other;
		index_mat++;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	this->index_mat = other.index_mat;
	for (int i = 0; i < NUMOFMAT; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = 0;
	}
	return (*this);
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < index_mat; i++)
	{
		if (materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	return (NULL);
}
