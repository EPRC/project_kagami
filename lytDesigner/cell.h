#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "layer.h"
#include "point.h"

class Cell : public QObject
{
    Q_OBJECT
public:
    explicit Cell(QObject *parent = 0);
    ~Cell();

    int childCount() const;
    int pointCount() const ;
    int getChildNum(Cell *child) const;
    int getRowNum() const;

    QString getName() const;

    Cell* getParent() const;
    Cell* getChild(const int &row) const;
    Layer* getLayer() const;

    bool setLayer(Layer *ly);
    bool setName(const QString &namep);
    bool setPoint(int nth, const Point &p);
    bool setPointSet(QList<Point> *p);
    void appendPoint(const Point &p);

    void setParent(Cell *parent);
    void removeParent();
    void appendChild(Cell *child);
    void removeChild(Cell *child);
    bool insertChildren(const int &position, const int &count, Cell *child = nullptr);
    bool removeChildren(const int &position, const int &count, const bool &destroy);

    static const int NAME       =0;
    static const int LAYER      =1;
    static const int DESCRIPTION=2;
    static const int POINT      =3;

signals:

public slots:

private:
    QString name;
    Cell *parentCell;
    QList<Cell*> *childCells;
    Layer *layer;
    QList<Point> *point;
};

#endif // CELL_H
