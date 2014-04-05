#ifndef POINT_H
#define POINT_H

#include "abstractshape_global.h"

class ABSTRACTSHAPESHARED_EXPORT Point
{
public:
    Point();
    Point(const double &xp, const double &yp);
    Point(const Point &p);

    double x;
    double y;
};

#endif // POINT_H
