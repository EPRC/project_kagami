#include "abstractshape.h"


AbstractShape::AbstractShape()
{
}

AbstractShape::~AbstractShape()
{

}

int AbstractShape::childCount() const
{
    return childCells->size();
}

int AbstractShape::pointCount() const
{
    return points->size();
}

int AbstractShape::getChildNum(AbstractShape *child) const
{
    if (child){
        return childCells->indexOf(child);
    }
    return -1;
}

int AbstractShape::getRowNum() const
{
    if (parentCell){
        return parentCell->getChildNum(const_cast<AbstractShape*>(this));
    }
    return -1;
}

QString AbstractShape::getName() const
{
    return name;
}

AbstractShape *AbstractShape::getParent() const
{
    if (parentCell)
        return parentCell;
    return nullptr;
}

AbstractShape *AbstractShape::getChild(const int &row) const
{
    if (row < childCount())
        return childCells->at(row);
    return nullptr;
}

QList<Point *> *AbstractShape::getPoint() const
{
    return points;
}

Layer *AbstractShape::getLayer() const
{
    return layer;
}

bool AbstractShape::setLayer(Layer *ly)
{
    if (ly){
        layer = ly;
        return true;
    }
    return false;
}

bool AbstractShape::setName(const QString &namep)
{
    name = namep;
    return true;
}

bool AbstractShape::setPoint(int nth, Point *p)
{
    if (nth < pointCount()){
        points->replace(nth,p);
        return true;
    }
    return false;
}

bool AbstractShape::setPointSet(QList<Point*> *p)
{
    if (p){
        points = p;
        return true;
    }
    return false;
}

bool AbstractShape::appendPoint(Point *p)
{
    if (p){
        points->append(p);
        return true;
    }
    return false;
}

bool AbstractShape::setParent(AbstractShape *parent)
{
    if (parent){
        parentCell = parent;
        return true;
    }
    return false;
}

bool AbstractShape::removeParent()
{
    parentCell = nullptr;
    return true;
}

bool AbstractShape::appendChild(AbstractShape *child)
{
    if (child){
        childCells->append(child);
        return true;
    }
    return false;
}

bool AbstractShape::removeChild(AbstractShape *child)
{
    if (child){
        if (childCells->removeAll(child))
            return true;
    }
    return false;
}

bool AbstractShape::insertChildren(const int &position, const int &count, AbstractShape *child)
{
    AbstractShape *newcell;
    if (position <0 || position > childCells->size())
        return false;
    for (int i=0; i<count; i++){
        if(child)
            newcell = child;
        else
            newcell = this->createShape();
        newcell->setParent(this);
        childCells->insert(position, newcell);
    }
    return true;
}

bool AbstractShape::removeChildren(const int &position, const int &count, const bool &destroy)
{
    if (position <0 || position > childCells->size())
        return false;
    for (int i=0; i<count; i++){
        if(destroy)
            delete(childCells->takeAt(position));
        else
            childCells->removeAt(position);
    }
    return true;
}
