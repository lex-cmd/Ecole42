#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	protected:
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
	
		Brain		*getBrain() const;
		void		makeSound() const;
		Cat			&operator=(const Cat &other);
		Animal 		&operator=(const Animal &other);
};

#endif
