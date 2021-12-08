#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = zombieHorde(ALL_ZOMBIE, "Keksik");
	for (int act_zombie = 0; act_zombie < ALL_ZOMBIE; act_zombie++)
		zombie[act_zombie].announce();	
	delete[] zombie;
}
