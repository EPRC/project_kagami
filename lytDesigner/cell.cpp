#include "cell.h"

Cell::Cell(QObject *parent) :
    QObject(parent)
{
    name=QString("[New Cell]");
    parentCell = nullptr;
    childCells = new QList<Cell*>();
    point = new QList<Point>();
}

Cell::~Cell()
{

}

int Cell::childCount() const
{
    return childCells->size();
}

int Cell::pointCount() const
{
    return point->size();
}

int Cell::getChildNum(Cell *child) const
{
    if (child){
        return childCells->indexOf(child);
    }
    return -1;
}

int Cell::getRowNum() const
{
    if (parentCell){
        return parentCell->getChildNum(const_cast<Cell*>(this));
    }
    return -1;
}

QString Cell::getName() const
{
    return name;
}

Cell *Cell::getParent() const
{
    return parentCell;
}

Cell *Cell::getChild(const int &row) const
{
    if (row < childCount())
        return childCells->at(row);
    return nullptr;
}

Layer *Cell::getLayer() const
{
    return layer;
}

bool Cell::setLayer(Layer *ly)
{
    if (ly){
        this->layer = ly;
        return true;
    }
    return false;
}

bool Cell::setName(const QString &namep)
{
    name = namep;
    return true;
}

bool Cell::setPoint(int nth, const Point &p)
{
    if (nth < pointCount()){
        point->replace(nth,p);
        return true;
    }
    return false;
}

bool Cell::setPointSet(QList<Point> *p)
{
    if (p){
        point = p;
        return true;
    }
    return false;
}

void Cell::appendPoint(const Point &p)
{
    point->append(p);
}

void Cell::setParent(Cell *parent)
{
    if (parent)
        parentCell = parent;
}

void Cell::removeParent()
{
    parentCell = nullptr;
}

void Cell::appendChild(Cell *child)
{
    childCells->append(child);
}

void Cell::removeChild(Cell *child)
{
    childCells->removeAll(child);
}

bool Cell::insertChildren(const int &position, const int &count, Cell *child)
{
    Cell* newcell;
    if (position <0 || position > childCells->size())
        return false;
    for (int i=0; i<count; i++){
        if(child)
            newcell = child;
        else
            newcell = new Cell();
        newcell->setParent(this);
        childCells->insert(position, newcell);
    }
    return true;
}

bool Cell::removeChildren(const int &position, const int &count, const bool &destroy)
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
