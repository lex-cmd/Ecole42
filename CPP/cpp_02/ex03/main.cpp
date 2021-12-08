#include "Point.hpp"
#include "Fixed.hpp"

int main( void )
{
	const Point	a(100000, 2000);
	const Point	b(3000, 100);
	const Point	c(100, 0);
	const Point	d(0, 0);
	std::cout << "result: " << bsp(a, b, c, d) << std::endl;
	const Point	e(2, 3);
	const Point	f(2, 12);
	const Point	g(100, 0);
	const Point	h(3, 2);
	std::cout << "result: " << bsp(e, f, g, h) << std::endl;
	const Point	i(1.2, 0.13);
	const Point	j(1.2, 3.712);
	const Point	k(1.30405, 0.235);
	const Point	l(3.324, 22.24324);
	std::cout << "result: " << bsp(e, f, g, h) << std::endl;
	return 0;
}