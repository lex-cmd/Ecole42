#include "Point.hpp"
#include "Fixed.hpp"

Point::~Point()
{
	
}

Point::Point()
{
	const_cast<Fixed&>(x) = Fixed(0);
	const_cast<Fixed&>(y) = Fixed(0);
}

Point::Point(Point const &other)
{
	*this = other;
}

Point::Point(const float x, const float y)
{
	const_cast<Fixed&>(this->x) = Fixed(x);
	const_cast<Fixed&>(this->y) = Fixed(y);
}

const Fixed	Point::getX() const
{
	return (this->x);
}

const Fixed	Point::getY() const
{
	return (this->y);
}

Point &Point::operator=(Point const &other)
{
	const_cast<Fixed&>(x) = other.x;
	const_cast<Fixed&>(y) = other.y;
	return (*this);
}
