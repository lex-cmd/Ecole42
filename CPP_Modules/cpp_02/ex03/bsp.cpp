#include "Point.hpp"

/* Вычисляет положение точки D(xd,yd) относительно прямой AB */
Fixed point_search(Fixed xa, Fixed ya, Fixed xb, Fixed yb, Fixed xd, Fixed yd) 
{
	return (xd - xa) * (yb - ya) - (yd - ya) * (xb - xa);
}
 
/* Лежат ли точки C и D с одной стороны прямой (AB)? */
bool f(Fixed xa, Fixed ya, Fixed xb, Fixed yb, Fixed xc, Fixed yc, Fixed xd, Fixed yd) 
{
	Fixed res;

	res = (point_search(xa, ya, xb, yb, xc, yc) * point_search(xa, ya, xb, yb, xd, yd));
	return (res.toFloat() >= 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (f(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY(), point.getX(), point.getY()) &&
		f(b.getX(), b.getY(), c.getX(), c.getY(), a.getX(), a.getY(), point.getX(), point.getY()) && 
		f(c.getX(), c.getY(), a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY()))
		return 1;
	return 0;
}
