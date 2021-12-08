	#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	protected:
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		void		makeSound() const;
		Brain		*getBrain() const;
		Dog			&operator=(const Dog &other);
		Animal 		&operator=(const Animal &other);
};

#endif
