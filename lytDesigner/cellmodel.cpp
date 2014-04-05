#include "cellmodel.h"

CellModel::CellModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    header << "Name";
    header << "Layer";
}

CellModel::~CellModel()
{

}

AbstractShape *CellModel::getCellByIndex(const QModelIndex &index) const
{
    if (!index.isValid())
        return topCell;
    return static_cast<AbstractShape*>(index.internalPointer());
}

bool CellModel::setTopCell(AbstractShape *top)
{
    if (top){
        beginResetModel();
        topCell = top;
        endResetModel();
        return true;
    }
    return false;
}

QModelIndex CellModel::index(int row, int column, const QModelIndex &parent) const
{
    AbstractShape* pCell;
    if(!hasIndex(row,column,parent))
        return QModelIndex();
    // TODO try to cancel this part
    if (!parent.isValid())
        pCell = topCell;
    else
        pCell = getCellByIndex(parent);

    AbstractShape* cCell = pCell->getChild(row);
    return createIndex(row,column,cCell);
}

QModelIndex CellModel::parent(const QModelIndex &child) const
{
    AbstractShape* pCell;
    if (!child.isValid()){
        return QModelIndex();
    }else{
        pCell = getCellByIndex(child)->getParent();
    }
    return createIndex(pCell->getRowNum(),0,pCell);
}

QModelIndex CellModel::sibling(int row, int column, const QModelIndex &idx) const
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    Q_UNUSED(idx);
    return QModelIndex();
}

Qt::ItemFlags CellModel::flags(const QModelIndex &index) const
{
    if (index.column() >= CellModel::COL_MAX || !index.isValid())
        return 0;
    else
        return Qt::ItemIsSelectable | QAbstractItemModel::flags(index);
}

int CellModel::rowCount(const QModelIndex &parent) const
{
    return getCellByIndex(parent)->childCount();
}

int CellModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return CellModel::COL_MAX;
}

bool CellModel::hasChildren(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return true;

    if (getCellByIndex(parent)->childCount()==0)
        return false;
    else
        return true;
}

QVariant CellModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    switch(index.column())
    {
        case NAME :
            return getCellByIndex(index)->getName();
        case LAYER:
            return getCellByIndex(index)->getLayer()->getName();
    }
    return QVariant();
}

bool CellModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    if (!index.isValid())
        return false;

    switch(index.column())
    {
        case NAME :
            return getCellByIndex(index)->setName(value.toString());
        case LAYER :
            return getCellByIndex(index)->setLayer(value.value<Layer*>());
        case DESCRIPTION:
            return true;
        case POINT:
            //return getCellByIndex(index)->setPointSet(value.value<QList<Point*>*>());
    }
    return false;
}

QVariant CellModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole || section >= CellModel::COL_MAX)
        return QVariant();

    return header.at(section);
}

bool CellModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole || section >= CellModel::COL_MAX)
        return false;

    header.replace(section,value);
    return true;
}

bool CellModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    Q_UNUSED(data);
    Q_UNUSED(action);
    Q_UNUSED(row);
    Q_UNUSED(column);
    Q_UNUSED(parent);
    return true;
}

bool CellModel::insertRows(int row, int count, const QModelIndex &parent)
{
    AbstractShape* pCell;
    bool result;

    if (!parent.isValid())
        pCell = topCell;
    else
        pCell = getCellByIndex(parent);

    if(row+count-1> pCell->childCount())
        return false;

    beginInsertRows(parent,row,row+count-1);
        result = pCell->insertChildren(row,count);
    endInsertRows();

    return result;
}

bool CellModel::removeRows(int row, int count, const QModelIndex &parent)
{
    AbstractShape* pCell;
    bool result;

    if (!parent.isValid())
        pCell = topCell;
    else
        pCell = getCellByIndex(parent);

    if(row+count-1> pCell->childCount())
        return false;

    beginRemoveRows(parent,row,row+count-1);
        result = pCell->removeChildren(row,count,true);
    endRemoveRows();

    return result;
}

bool CellModel::moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild)
{
    AbstractShape* srcCell;
    AbstractShape* desCell;
    bool result = true;

    if (!sourceParent.isValid())
        srcCell = topCell;
    else
        srcCell = getCellByIndex(sourceParent);

    if (!destinationParent.isValid())
        desCell = topCell;
    else
        desCell = getCellByIndex(destinationParent);

    if (sourceRow+count-1 > srcCell->childCount() || destinationChild > desCell->childCount())
        return false;

    beginMoveRows(sourceParent,sourceRow,sourceRow+count-1,destinationParent,destinationChild);
        for (int i=0; i<count; i++){
            result &= desCell->insertChildren(destinationChild,1,srcCell->getChild(sourceRow));
            result &= srcCell->removeChildren(sourceRow,1,false);
        }
    endMoveRows();

    return result;
}

QModelIndexList CellModel::match(const QModelIndex &start, int role, const QVariant &value, int hits, Qt::MatchFlags flags) const
{
    Q_UNUSED(start);
    Q_UNUSED(role);
    Q_UNUSED(value);
    Q_UNUSED(hits);
    Q_UNUSED(flags);
    return QModelIndexList();
}
