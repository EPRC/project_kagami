#include "layertablemodel.h"

LayerTableModel::LayerTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    header << "Color";
    header << "Num";
    header << "Name";
    header << "Depth";
}

LayerTableModel::~LayerTableModel()
{

}

int LayerTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if (layerList)
        return this->layerList->size();
    else
        return 0;
}

int LayerTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LayerTableModel::COL_MAX;
}

Qt::ItemFlags LayerTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || index.column() >= LayerTableModel::COL_MAX)
        return 0;

    return Qt::ItemIsSelectable | QAbstractItemModel::flags(index);
}

QModelIndex LayerTableModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if (row >= this->layerList->size() || column >= LayerTableModel::COL_MAX)
        return QModelIndex();
    else
        return createIndex(row,column);
}

QVariant LayerTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= this->layerList->size())
        return QVariant();
    if (index.column() == Layer::COLOR && role == Qt::DisplayRole)
        return this->layerList->at(index.row())->getColor();

    if (role == Qt::DisplayRole)
        switch(index.column())
        {
            //case Layer::COLOR:
                //return this->layerList->at(index.row())->getColor();
            case Layer::NUMBER:
                return this->layerList->at(index.row())->getNum();
            case Layer::NAME:
                return this->layerList->at(index.row())->getName();
            case Layer::DEPTH:
                return this->layerList->at(index.row())->getDepth();
        }
    return QVariant();
}

QVariant LayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole || section >= LayerTableModel::COL_MAX)
        return QVariant();
    return header.at(section);
}

bool LayerTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if (row >= this->layerList->size() || count >= LayerTableModel::COL_MAX)
        return false;

    beginInsertRows(QModelIndex(),row,row+count-1);
        for(int i=0; i<count; i++){
            Layer *layer = new Layer();
            this->layerList->append(layer);
        }
    endInsertRows();
    return true;
}

bool LayerTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if (row >= this->layerList->size() || (row+count-1) >= this->layerList->size() || count >= LayerTableModel::COL_MAX)
        return false;
    beginRemoveRows(QModelIndex(),row,row+count-1);
        for(int i=0; i<count; i++){
            this->layerList->removeAt(row);
        }
    endRemoveRows();
    return true;
}

bool LayerTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::DisplayRole || index.row() >= layerList->size())
        return false;

    switch(index.column())
    {
        case Layer::COLOR:
            layerList->at(index.row())->setColor(value);
            break;
        case Layer::NUMBER:
            layerList->at(index.row())->setNum(value);
            break;
        case Layer::NAME:
            layerList->at(index.row())->setName(value);
            break;
        case Layer::DEPTH:
            layerList->at(index.row())->setDepth(value);
            break;
        default:
            return false;
    }
    return true;
}

bool LayerTableModel::setLayerList(QList<Layer *> *listSource)
{
    beginResetModel();
    this->layerList=listSource;
    endResetModel();
    return true;
}

bool LayerTableModel::isExistNum(const int &num) const
{
    if (layerList){
        for (int i=0; i<layerList->size();i++){
            if (layerList->at(i)->getNum().toInt() == num)
                return true;
        }
    }
    return false;
}

Layer *LayerTableModel::getLayer(const int &i) const
{
    if (i<=layerList->size())
        return layerList->at(i);
    return nullptr;
}
