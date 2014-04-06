#ifndef CELL_H
#define CELL_H

#include <QGridLayout>
#include <QString>
#include "../lytDesigner/layer.h"
#include "abstractshape_global.h"

class ABSTRACTSHAPESHARED_EXPORT Cell
{
public:
    Cell();

    QString getName();
    Layer* getLayer() const;
    virtual QGridLayout* getQGridLayout();
    virtual Cell* createCell();
    virtual bool applySetting();

    bool setName(QString namep);
    bool setLayer(Layer *ly);

    // Hierarchy related
    int childCount() const;
    int getChildNum(Cell *child) const;
    int getRowNum() const;

    Cell* getParent() const;
    Cell* getChild(const int &row) const;

    bool setParent(Cell *parent);
    bool removeParent();
    bool appendChild(Cell *child);
    bool removeChild(Cell *child);
    bool insertChildren(const int &position, const int &count, Cell *child = 0);
    bool removeChildren(const int &position, const int &count, const bool &destroy);

protected:
    QString name;
    Layer* layer;
    Cell* parentCell;
    QList<Cell*> *childCells;
};

#endif // CELL_H
