#include "layerwindow.h"

LayerWindow::LayerWindow(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout(this);
    treeview = new QTreeView(this);
    tableview = new QTableView(this);
    listview = new QListView(this);
    manager = new LayerManager(this);
    cellWindow = new CellWindow(this);

    //topCell = new Rect();

    setRMMenu();

    Layer *layer1 = new Layer();
    layer1->setColor(QColor(Qt::black));
    layer1->setName(QString("Layer1"));
    layer1->setNum(1);
    layer1->setDepth(0.1);
    layerList.append(layer1);

    Layer *layer2 = new Layer();
    layer2->setColor(QColor(Qt::white));
    layer2->setName(QString("Layer2"));
    layer2->setNum(2);
    layer2->setDepth(0.3);
    layerList.append(layer2);

    Layer *layer3 = new Layer();
    layer3->setColor(QColor(Qt::white));
    layer3->setName(QString("Layer3"));
    layer3->setNum(3);
    layer3->setDepth(0.4);
    layerList.append(layer3);

    Layer *layer4 = new Layer();
    layer4->setColor(QColor(Qt::white));
    layer4->setName(QString("Layer4"));
    layer4->setNum(4);
    layer4->setDepth(1.4);
    layerList.append(layer4);

    Layer *layer5 = new Layer();
    layer5->setColor(QColor(Qt::white));
    layer5->setName(QString("Layer5"));
    layer5->setNum(5);
    layer5->setDepth(1.4);
    layerList.append(layer5);

    layerModel = new LayerTableModel();
    layerModel->setLayerList(&layerList);
    cellModel = new CellModel();
    //cellModel->setTopCell(topCell);

    tableview->setModel(layerModel);
    tableview->setColumnHidden(0,true);
    //tableview->setRowHidden(0,true);
    listview->setModel(layerModel);
    listview->setModelColumn(2);
    //treeview->setModel(cellModel);

    layout->addWidget(tableview);
    layout->addWidget(listview);
    layout->addWidget(treeview);

    this->setLayout(layout);
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    connect(tableview,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onTableViewShowMenu(QPoint)));
    connect(treeview,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onTreeViewShowMenu(QPoint)));
    connect(manager,SIGNAL(addLayer(QColor,int,QString,double)),this,SLOT(transLayer(QColor,int,QString,double)));
    connect(this,SIGNAL(addLayerSucceed()),manager,SLOT(addLayerSucceed()));
    connect(this,SIGNAL(addLayerFailed(int)),manager,SLOT(addLayerFail(int)));

}

LayerWindow::~LayerWindow()
{

}

void LayerWindow::setRMMenu()
{
    tableview->setContextMenuPolicy(Qt::CustomContextMenu);
    treeview->setContextMenuPolicy(Qt::CustomContextMenu);
    rmmenu = new QMenu(this);
    rmcmenu = new QMenu(this);
    QAction *addLayerAction = new QAction("&Add Layer",rmmenu);
    QAction *deleteLayerAction = new QAction("&Delete Layer",rmmenu);

    rmmenu->addAction(addLayerAction);
    rmmenu->addAction(deleteLayerAction);

    QAction *addCellAction = new QAction("&Add Cell",rmcmenu);
    QAction *deleteCellAction = new QAction("&Delete Layer",rmcmenu);

    rmcmenu->addAction(addCellAction);
    rmcmenu->addAction(deleteCellAction);

    connect(addLayerAction,SIGNAL(triggered()),this,SLOT(addLayerRequest()));
    connect(deleteLayerAction,SIGNAL(triggered()),this,SLOT(deleteLayerRequest()));
    connect(addCellAction,SIGNAL(triggered()),this,SLOT(addCellRequest()));
    connect(deleteLayerAction,SIGNAL(triggered()),this,SLOT(deleteCellRequest()));

}

void LayerWindow::onTableViewShowMenu(const QPoint)
{
    rmmenu->exec(QCursor::pos());
}

void LayerWindow::onTreeViewShowMenu(const QPoint)
{
    rmcmenu->exec(QCursor::pos());
}

void LayerWindow::addCellRequest()
{
    cellWindow->reset(0);
    cellWindow->setLayerModel(this->layerModel);
    cellWindow->exec();
}

void LayerWindow::deleteCellRequest()
{

}

void LayerWindow::addLayerRequest()
{
    manager->exec();
}

void LayerWindow::deleteLayerRequest()
{
    QModelIndex index = tableview->currentIndex();
    if (index.isValid())
        layerModel->removeRow(index.row(),QModelIndex());
}

void LayerWindow::transLayer(const QColor &colorp, const int &nump, const QString &namep, const double &depthp)
{
    QModelIndex index;
    if (!layerModel->isExistNum(nump)){
        int row = layerModel->rowCount(QModelIndex());
        layerModel->insertRow(row-1,QModelIndex());
        index = layerModel->index(row,Layer::COLOR,QModelIndex());
        layerModel->setData(index,QVariant(colorp),Qt::DecorationRole);
        index = layerModel->index(row,Layer::NUMBER,QModelIndex());
        layerModel->setData(index,QVariant(nump),Qt::DisplayRole);
        index = layerModel->index(row,Layer::NAME,QModelIndex());
        layerModel->setData(index,QVariant(namep),Qt::DisplayRole);
        index = layerModel->index(row,Layer::DEPTH,QModelIndex());
        layerModel->setData(index,QVariant(depthp),Qt::DisplayRole);
        emit addLayerSucceed();
    }else{
        emit addLayerFailed(0);
    }
}
