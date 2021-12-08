#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
	
		void highFivesGuys(void);
};

#endif
