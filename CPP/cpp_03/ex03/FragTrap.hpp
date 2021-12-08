#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	private:

	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
	
		void 	attack(std::string const &target);
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
