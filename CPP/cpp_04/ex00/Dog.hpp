#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
	protected:
	public:
		void	makeSound() const;
		Dog();
		~Dog();
};

#endif
