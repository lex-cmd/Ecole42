#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_m = newZombie("Petrubrator");
	Zombie	zombie1("Ponchick");
	Zombie	zombie2("Keksick");
	Zombie	zombie3("Pancake");
	Zombie	zombie4;


	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	zombie4.announce();
	zombie_m->announce();
	delete zombie_m;
}
