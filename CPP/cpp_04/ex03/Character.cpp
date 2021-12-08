#include "Character.hpp"

Character::~Character()
{
	// std::cout << "Вызван деструктор Character" << std::endl;
}

Character::Character()
{
	// std::cout << "Вызван конструктор Character" << std::endl;
	this->name = "Link";
	this->index_inv = 0;
	for (int i = 0; i < NUMOFCELL; i++)
		inv[i] = 0;
}

Character::Character(std::string name)
{
	this->name = name;
	// std::cout << "Вызван конструктор Character " << this->name << std::endl;
	index_inv = 0;
	for (int i = 0; i < NUMOFCELL; i++)
		inv[i] = 0;
}

Character::Character(const Character &other)
{
	// std::cout << "Вызван конструктор Character" << std::endl;
	this->name = other.name;
	this->index_inv = other.index_inv;
	for	(int i = 0; i < NUMOFCELL; i++)
	{
		if (other.inv[i])
			this->inv[i] = other.inv[i];
		else
			inv[i] = 0;
	}
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (this->index_inv < NUMOFCELL)
	{
		this->inv[index_inv] = m;
		std::cout << "Экипирована материя " << this->inv[index_inv]->getType() << std::endl;
		index_inv++;
	}
	else
		std::cout << "Ячейки инвентаря заполнены" << std::endl; return;
}

void Character::unequip(int idx)
{
	if (inv[idx] != 0 && idx < NUMOFCELL)
	{
		std::cout << "Ты выкинул " << this->inv[idx]->getType() << std::endl;
		inv[idx] = 0;
		this->index_inv--;
	}
	else
		std::cout << "Ячейка уже пустая" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (inv[idx])
		inv[idx]->use(target);
	else
		std::cout << "Отсутсвует материя в интвентаре" << std::endl;
}

Character &Character::operator=(const Character& target)
{
	this->name = target.name;
	if (this == &target)
		return (*this);

	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
		inv[i] = 0;
		if (target.inv[i])
			this->inv[i] = target.inv[i];
		else
			inv[i] = 0;
	}
	return (*this);
}
