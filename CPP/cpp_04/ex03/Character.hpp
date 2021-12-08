#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# define NUMOFCELL 4

class Character : public ICharacter
{
	private:
		std::string	name;
		int			index_inv;
		AMateria	*inv[NUMOFCELL];
	public:
		~Character();
		Character();
		Character(std::string name);
		Character(const Character &other);

		std::string const &getName() const;
		void equip(AMateria* mat);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character &operator=(const Character& target);
};

#endif