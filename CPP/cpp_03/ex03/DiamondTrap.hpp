#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		~DiamondTrap();
		DiamondTrap();
		DiamondTrap(std::string name);

		void attack(std::string const &target);
		void whoAmI();
};

#endif
