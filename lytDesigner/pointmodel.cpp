#include "pointmodel.h"

PointModel::PointModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

PointModel::~PointModel()
{

}

bool PointModel::setPointList(QList<Point*> *plist)
{
    if (plist){
        beginResetModel();
            this->pointList = plist;
        endResetModel();
        return true;
    }
    return false;
}

int PointModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if (pointList){
        return pointList->size();
    }
    return 0;
}

QModelIndex PointModel::index(int &row, int &column, const QModelIndex &parent) const
{
    Q_UNUSED(column);
    Q_UNUSED(parent);
    if (row >= pointList->size())
        return QModelIndex();

    return createIndex(row,column);
}

QVariant PointModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole || index.row() >= pointList->size())
        return QVariant();
    //return QString("(").append(QString::number(pointList->at(index.row()).x)).append(",").append(QString::number(pointList->at(index.row()).y)).append(")");
    return QVariant();
}

Qt::ItemFlags PointModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    else
        return Qt::ItemIsSelectable | QAbstractItemModel::flags(index);
}
