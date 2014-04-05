#ifndef LAYERWINDOW_H
#define LAYERWINDOW_H

#include <QWidget>
#include <QList>
#include <QTreeView>
#include <QTableView>
#include <QListView>
#include <QMenu>
#include <QAction>
#include <QGridLayout>
#include "layer.h"
#include "layertablemodel.h"
#include "layermanger.h"
#include "cellmodel.h"
#include "cellwindow.h"
#include "../rect/rect.h"

#include <QDebug>

class LayerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LayerWindow(QWidget *parent = 0);
    ~LayerWindow();

    LayerTableModel *layerModel;
    CellModel *cellModel;

    LayerManager *manager;
    CellWindow *cellWindow;

    QList<Layer*> layerList;
    Rect *topCell;

    QTreeView *treeview;
    QListView *listview;
    QTableView *tableview;
    QMenu *rmmenu;
    QMenu *rmcmenu;

    QGridLayout *layout;

    void setRMMenu();

signals:
    void addLayerSucceed();
    void addLayerFailed(const int&);

public slots:
    void onTableViewShowMenu(const QPoint);
    void onTreeViewShowMenu(const QPoint);
    void addCellRequest();
    void deleteCellRequest();
    void addLayerRequest();
    void deleteLayerRequest();
    void transLayer(const QColor &colorp, const int &nump, const QString &namep, const double &depthp);

};

#endif // LAYERWINDOW_H
