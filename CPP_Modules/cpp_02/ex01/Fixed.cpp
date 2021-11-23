#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixpoint = 0;
}

Fixed::Fixed(const int value)
{
	this->fixpoint = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
	this->fixpoint = roundf(value * (1 << Fixed::bits));
}

int	Fixed::toInt(void) const
{
	return (this->fixpoint >> Fixed::bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixpoint / float(1 << Fixed::bits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixpoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member function called" << std::endl;
	this->fixpoint = raw;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixpoint = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
