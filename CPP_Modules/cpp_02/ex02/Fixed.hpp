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

		bool operator>(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;

		Fixed operator+(Fixed const &other);
		Fixed operator-(Fixed const &other);
		Fixed operator*(Fixed const &other);
		Fixed operator/(Fixed const &other);
		Fixed operator++(); /* postfix version */
		Fixed operator--(); /* postfix version */
		Fixed operator++(int); /* prefix verson */
		Fixed operator--(int); /* prefix verson */

		static Fixed &min(Fixed &value1, Fixed &value2);
		static Fixed const &min(Fixed const &value1, Fixed const &value2);
		static Fixed &max(Fixed &value1, Fixed &value2);
		static Fixed const &max(Fixed const &value1, Fixed const &value2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

	Fixed const &max(Fixed const &value1, Fixed const &value2);
	Fixed &max(Fixed &value1, Fixed &value2);
	Fixed const &min(Fixed const &value1, Fixed const &value2);
	Fixed &min(Fixed &value1, Fixed &value2);
	std::ostream &operator<<(std::ostream &out, Fixed const &other);

#endif
