#include "abstractshape.h"


AbstractShape::AbstractShape()
{
    points = new QList<Point*>();
}

AbstractShape::~AbstractShape()
{

}

int AbstractShape::pointCount() const
{
    return points->size();
}

QList<Point *> *AbstractShape::getPoint() const
{
    return points;
}
