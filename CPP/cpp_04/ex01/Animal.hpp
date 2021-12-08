#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal
{
	private:
	protected:
		std::string type;
	public:
							Animal();
							Animal(const Animal &other);
		virtual 			~Animal();

		virtual void		makeSound() const;
		const std::string	getType() const;
		virtual Animal 		&operator=(const Animal &other);
		virtual Brain		*getBrain() const = 0;
};

		std::ostream	&operator<<(std::ostream &out, const Animal &other);

#endif
