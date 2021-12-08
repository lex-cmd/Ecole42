#include "Fixed.hpp"

Fixed::~Fixed()
{
	// std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixpoint);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "getRawBits member function called" << std::endl;
	this->fixpoint = raw;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->fixpoint = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(Fixed const &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (Fixed::getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)
{
	this->setRawBits(this->getRawBits() + other.getRawBits());
	return (*this);
}

Fixed Fixed::operator-(Fixed const &other)
{
	this->setRawBits(this->getRawBits() + other.getRawBits());
	return (*this);
}

Fixed Fixed::operator*(Fixed const &other)
{
	setRawBits(((long)this->getRawBits() * (long)other.getRawBits()) / (1 << Fixed::bits));
	return (*this);
}

Fixed Fixed::operator/(Fixed const &other)
{
	setRawBits(((long)this->getRawBits() * (1 << Fixed::bits)) / (long)other.getRawBits());
	return (*this);
}

Fixed Fixed::operator++()
{
	this->fixpoint++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->fixpoint--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &value1, Fixed &value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}

Fixed const &Fixed::min(Fixed const &value1, Fixed const &value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}


Fixed &Fixed::max(Fixed &value1, Fixed &value2)
{
	if (value1 < value2)
		return (value2);
	return (value1);
}

Fixed const &Fixed::max(Fixed const &value1, Fixed const &value2)
{
	if (value1 < value2)
		return (value2);
	return (value1);
}
