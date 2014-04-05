#include "point.h"

Point::Point()
{
    x=0;
    y=0;
}

Point::Point(const double &xp, const double &yp)
{
    x = xp;
    y = yp;
}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
}
