#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap trap1;
	ClapTrap trap2("Bals Trap");
	ClapTrap trap3("Souce Trap");
	ClapTrap trap4("Spaghetti  Trap");

	trap1.attack("Hole");
	trap2.attack("Circle");
	trap3.attack("Ketchup");
	trap4.attack("Your mouth");
	trap4.takeDamage(5);
}
