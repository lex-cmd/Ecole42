#include <stdio.h>
 
// Вычисляет положение точки D(xd,yd) относительно прямой AB
double g(double xa, double ya, double xb, double yb, double xd, double yd) 
{
    return (xd - xa) * (yb - ya) - (yd - ya) * (xb - xa);
}
 
// Лежат ли точки C и D с одной стороны прямой (AB)?
bool f(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd) 
{
    return g(xa, ya, xb, yb, xc, yc) * g(xa, ya, xb, yb, xd, yd) >= 0;
}
 
int main() 
{
    double xa, ya, xb, yb, xc, yc, xd, yd;
    scanf("%lf%lf", &xa, &ya); // читаем координаты точки A
    scanf("%lf%lf", &xb, &yb); // читаем координаты точки B
    scanf("%lf%lf", &xc, &yc); // читаем координаты точки C
    scanf("%lf%lf", &xd, &yd); // читаем координаты точки D
    printf( f(xa,ya,xb,yb,xc,yc,xd,yd) && f(xb,yb,xc,yc,xa,ya,xd,yd) && 
            f(xc,yc,xa,ya,xb,yb,xd,yd) ? "yes" : "no");
    return 0;
}
