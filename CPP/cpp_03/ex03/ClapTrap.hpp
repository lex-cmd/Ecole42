#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string			name;
		int					hp;
		int					energy;
		int					dmg;

	public:

		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);

		std::string getName() const;
		int			getHP() const;
		int			getEnergy() const;
		int			getDmg() const;
		void		setName(std::string name);
		void		setHP(int hp);
		void		setEnergy(int energy);
		void		setDmg(int dmg);

		void 		attack(std::string const &target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
};

#endif
