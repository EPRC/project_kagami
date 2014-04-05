#ifndef BBOX_H
#define BBOX_H

#include "abstractshape_global.h"

class ABSTRACTSHAPESHARED_EXPORT BBox
{
public:
    BBox();

    double left;
    double top;
    double right;
    double bottom;
};

#endif // BBOX_H
