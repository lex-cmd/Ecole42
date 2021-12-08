#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	trap1;
	ClapTrap	trap2("Bals Trap");
	ClapTrap	trap3("Souce Trap");
	ClapTrap	trap4("Spaghetti  Trap");
	ScavTrap	trap5("Shampoo Trap");
	ScavTrap	trap6;

	trap1.attack("Hole");
	trap2.attack("Circle");
	trap3.attack("Ketchup");
	trap4.attack("Your mouth");

	trap4.takeDamage(5);

	trap5.guardGate();
	trap6.guardGate();

	trap5.attack("Your hair");
	trap5.takeDamage(5);
	trap6.attack("Your body");
}

// int main(void)
// {
// 	ScavTrap trap1;
// 	ScavTrap trap2("VooDoo");
// }
