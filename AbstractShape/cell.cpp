#include "cell.h"

Cell::Cell()
{
}

Layer *Cell::getLayer() const
{
    if (layer){
        return layer;
    }
    return nullptr;
}

QGridLayout *Cell::getQGridLayout()
{
    return new QGridLayout();
}

Cell *Cell::createCell()
{
    return new Cell();
}

bool Cell::applySetting()
{
    return true;
}

bool Cell::setName(QString namep)
{
    name = namep;
    return true;
}

int Cell::childCount() const
{
    if (childCells){
        return childCells->size();
    }
    return -1;
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

Cell *Cell::getParent() const
{
    if (parentCell){
        return parentCell;
    }
    return nullptr;
}

Cell *Cell::getChild(const int &row) const
{
    if (row<childCount())
        return childCells->at(row);
    return nullptr;
}

bool Cell::setParent(Cell *parent)
{
    if (parent){
        parentCell = parent;
        return true;
    }
    return false;
}

bool Cell::removeParent()
{
    parentCell = nullptr;
    return true;
}

bool Cell::appendChild(Cell *child)
{
    if (child){
        childCells->append(child);
        return true;
    }
    return false;
}

bool Cell::removeChild(Cell *child)
{
    if (child){
        if (childCells->removeAll(child))
            return true;
    }
    return false;
}

bool Cell::insertChildren(const int &position, const int &count, Cell *child)
{
    Cell *newcell;
    if (position <0 || position > childCells->size())
        return false;
    for (int i=0; i<count; i++){
        if(child)
            newcell = child;
        else
            newcell = this->createCell();
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
            childCells->takeAt(position);
        else
            childCells->removeAt(position);
    }
    return true;
}


