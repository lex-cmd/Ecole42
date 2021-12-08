#ifndef	BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

#define NUM_IDEAS 20

class Brain
{
	private:
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		std::string	ideas[NUM_IDEAS];
		Brain	&operator=(const Brain &other);
};

#endif
