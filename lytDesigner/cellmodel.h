#ifndef CELLMODEL_H
#define CELLMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "../AbstractShape/abstractshape.h"
#include <QDebug>

Q_DECLARE_METATYPE(Layer*)

class CellModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit CellModel(QObject *parent = 0);
    ~CellModel();

    AbstractShape* getCellByIndex(const QModelIndex &index) const;
    bool setTopCell(AbstractShape *top);

    static const int COL_MAX = 2;

    static const int NAME       =0;
    static const int LAYER      =1;
    static const int DESCRIPTION=2;
    static const int POINT      =3;

private:
    AbstractShape *topCell;
    QList<QVariant> header;

signals:

public slots:


    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QModelIndex sibling(int row, int column, const QModelIndex &idx) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    bool hasChildren(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild);
    QModelIndexList match(const QModelIndex &start, int role, const QVariant &value, int hits, Qt::MatchFlags flags) const;

};

#endif // CELLMODEL_H
