#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:

		int				fixpoint;
		static const int	bits = 8;

	public:

		Fixed();
		Fixed(Fixed const &other);
		~Fixed();

		Fixed &operator=(Fixed const &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif