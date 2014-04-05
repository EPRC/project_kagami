#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QWidget>
#include <QGridLayout>
#include "../lytDesigner/point.h"
#include "../lytDesigner/bbox.h"
#include "../lytDesigner/layer.h"
#include "abstractshape_global.h"

#define CENTER  0
#define TOP     1
#define RIGHT   2
#define BOTTOM  4
#define LEFT    8

#define EXT     16
#define INT     32


class ABSTRACTSHAPESHARED_EXPORT AbstractShape
{

public:
    AbstractShape();
    virtual ~AbstractShape();

    // GUI related

    virtual QWidget* getSettingPad() = 0;
    virtual QGridLayout* getLayout() = 0;

    // Factory method
    virtual AbstractShape* createShape() = 0;

    // Geomotry related
    virtual BBox* getBBox() const = 0;
    virtual QString getType() const = 0;
    virtual int  getAnchor() const = 0;
    virtual bool move(double &x, double &y) = 0;
    virtual bool translate(double &x, double &y) = 0;
    virtual bool changeAnchor(int &ref) = 0;
    virtual bool shrink(double &left, double &top, double &right, double &bottom) = 0;
    virtual bool expand(double &left, double &top, double &right, double &bottom) = 0;
    virtual bool copy(AbstractShape *shape) = 0;
    virtual bool compare(AbstractShape *shape) = 0;

    int anchor;


    // Hierarchy related
    int childCount() const;
    int pointCount() const ;
    int getChildNum(AbstractShape *child) const;
    int getRowNum() const;

    QString getName() const;

    AbstractShape* getParent() const;
    AbstractShape* getChild(const int &row) const;
    QList<Point*>* getPoint() const;
    Layer* getLayer() const;

    bool setLayer(Layer *ly);
    bool setName(const QString &namep);
    bool setPoint(int nth, Point *p);
    bool setPointSet(QList<Point*> *p);
    bool appendPoint(Point *p);

    bool setParent(AbstractShape *parent);
    bool removeParent();
    bool appendChild(AbstractShape *child);
    bool removeChild(AbstractShape *child);
    bool insertChildren(const int &position, const int &count, AbstractShape *child = nullptr);
    bool removeChildren(const int &position, const int &count, const bool &destroy);



protected:
    QString name;
    AbstractShape *parentCell;
    QList<AbstractShape*> *childCells;
    Layer *layer;
    QList<Point*> *points;
};

#endif // ABSTRACTSHAPE_H
