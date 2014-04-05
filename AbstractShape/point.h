#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(const double &xp, const double &yp);
    Point(const Point &p);

    double x;
    double y;
};

#endif // POINT_H
