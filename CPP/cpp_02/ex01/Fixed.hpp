#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:

		int					fixpoint;
		static const int	bits = 8;

	public:

		Fixed();
		Fixed(Fixed const &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed &operator=(Fixed const &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

	std::ostream &operator<<(std::ostream &out, Fixed const &other);

#endif
