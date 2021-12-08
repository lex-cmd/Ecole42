#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class Base
{
	private:
		std::string	name;
	public:
		Base();
		Base(std::string name);
		virtual ~Base();

		std::string getName() const;
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

std::ostream	&operator<<(std::ostream &out, const Base &other);

#endif