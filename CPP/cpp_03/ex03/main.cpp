#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
	DiamondTrap	trap1("Milk");

	trap1.whoAmI();
	trap1.attack("Hot chocolate");
}
