#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	private:

	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);

		void 	attack(std::string const &target);
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		void	guardGate();
};

#endif
