#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cctype>
#define ALL_ZOMBIE 10

class Zombie
{
	private:

	std::string	name;

	public:
	
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void		SetName(std::string name);
	std::string	GetName();
	void		announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
