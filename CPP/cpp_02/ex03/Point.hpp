#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed		x;
		const Fixed		y;

	public:
		Point();
		Point(const float x, const float y);
		Point(Point const &other);
		~Point();

		const Fixed getX() const;
		const Fixed getY() const;
		Point &operator=(Point const &other);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif