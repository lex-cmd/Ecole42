#include "Point.hpp"

/* Вычисляет положение точки point(pointx,pointx) относительно прямой AB */
Fixed get_pos_point(Fixed xa, Fixed ya, Fixed xb, Fixed yb, Fixed xd, Fixed yd) 
{
	return (xd - xa) * (yb - ya) - (yd - ya) * (xb - xa);
}
 
/* Лежат ли точки C и D с одной стороны прямой (AB)? */
bool get_pos_ab(Fixed xa, Fixed ya, Fixed xb, Fixed yb, Fixed xc, Fixed yc, Fixed pointx, Fixed pointy) 
{
	Fixed res;

	res = (get_pos_point(xa, ya, xb, yb, xc, yc) * get_pos_point(xa, ya, xb, yb, pointx, pointy));
	return (res.toFloat() >= 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (get_pos_ab(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY(), point.getX(), point.getY()) &&
		get_pos_ab(b.getX(), b.getY(), c.getX(), c.getY(), a.getX(), a.getY(), point.getX(), point.getY()) && 
		get_pos_ab(c.getX(), c.getY(), a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY()))
		return false;
	return true;
}
