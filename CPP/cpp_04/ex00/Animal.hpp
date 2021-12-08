#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	private:
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType(std::string type);
};

#endif
