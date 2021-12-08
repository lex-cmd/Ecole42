#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	trap1;
	ClapTrap	trap2("Bals Trap");
	ClapTrap	trap3("Souce Trap");
	ClapTrap	trap4("Spaghetti  Trap");
	ScavTrap	trap5("Shampoo Trap");
	ScavTrap	trap6;
	FragTrap	trap7("Mouse");
	// FragTrap	trap8;

	std::cout << std::endl;
	trap1.attack("Hole");
	trap2.attack("Circle");
	trap3.attack("Ketchup");
	trap4.attack("Your mouth");
	std::cout << std::endl;
	trap4.takeDamage(5);
	std::cout << std::endl;
	trap5.guardGate();
	trap6.guardGate();
	std::cout << std::endl;
	trap5.attack("Your hair");
	trap5.takeDamage(5);
	trap6.attack("Your body");
	std::cout << std::endl;
	trap7.attack("Cat");
	trap7.takeDamage(5);
	trap7.highFivesGuys();
	std::cout << std::endl;
}

// int main(void)
// {
// 	ScavTrap trap1;
// 	ScavTrap trap2("VooDoo");
// }
