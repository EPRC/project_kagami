#ifndef POINTMODEL_H
#define POINTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "point.h"

class PointModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PointModel(QObject *parent = 0);
    ~PointModel();

    bool setPointList(QList<Point*> *plist);

private:
    QList<Point*> *pointList;

signals:

public slots:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QModelIndex index(int &row, int &column, const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // POINTMODEL_H
