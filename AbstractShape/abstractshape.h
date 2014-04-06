#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QWidget>
#include <QGridLayout>
#include "bbox.h"
#include "point.h"
#include "cell.h"
#include "abstractshape_global.h"

#define CENTER  0
#define TOP     1
#define RIGHT   2
#define BOTTOM  4
#define LEFT    8

#define EXT     16
#define INT     32


class ABSTRACTSHAPESHARED_EXPORT AbstractShape : public Cell
{

public:
    AbstractShape();
    virtual ~AbstractShape();

    // Factory method
    //virtual Cell *createCell() = 0;

    // Geomotry related
    virtual BBox* getBBox() const = 0;
    virtual QString getType() const = 0;
    virtual int  getAnchor() const = 0;
    virtual bool move(double x, double y) = 0;
    virtual bool translate(double x, double y) = 0;
    virtual bool changeAnchor(int ref) = 0;
    virtual bool shrink(double left, double top, double right, double bottom) = 0;
    virtual bool expand(double left, double top, double right, double bottom) = 0;
    virtual bool copy(AbstractShape *shape) = 0;
    virtual bool compare(AbstractShape *shape) = 0;
    virtual bool overlap(AbstractShape *shape) = 0;

    // Shape method
    int anchor;

    int pointCount() const;
    QList<Point *> *getPoint() const;

public slots:
    virtual void onCreate() = 0;
    virtual void onSet() = 0;

protected:
    QList<Point*> *points;

};

#endif // ABSTRACTSHAPE_H
