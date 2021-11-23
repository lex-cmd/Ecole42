#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombie = new Zombie[N];
	
	for (int nb_zombie = 0; nb_zombie < N; nb_zombie++)
	{
		zombie[nb_zombie].SetName(name);
	}
	return (zombie);
}
