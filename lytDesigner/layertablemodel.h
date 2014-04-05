#ifndef LAYERMODEL_H
#define LAYERMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QList>
#include "layer.h"

#include <QDebug>

class LayerTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit LayerTableModel(QObject *parent = 0);
    ~LayerTableModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    bool setLayerList(QList<Layer*> *listSource);
    bool isExistNum(const int &num) const;
    Layer* getLayer(const int &i) const;

    static const int COL_MAX    =   4;

signals:

public slots:

private:
    QList<Layer*> *layerList;
    QList<QVariant> header;


};

#endif // LAYERMODEL_H
