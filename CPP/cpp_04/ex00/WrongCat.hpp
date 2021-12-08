#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	public:
		void makeSound() const;
		WrongCat();
		~WrongCat();
};

#endif