#include "cellwindow.h"

CellWindow::CellWindow(QWidget *parent) :
    QDialog(parent)
{
    initObj();
    reset(0);
}

CellWindow::~CellWindow()
{

}

bool CellWindow::setLayerModel(LayerTableModel *lm)
{
    if (lm){
        layerModel = lm;
        layerBox->setModel(lm);
        layerBox->setModelColumn(Layer::NAME);
        return true;
    }
    return false;
}

int CellWindow::checkMode()
{
    return this->mode;
}

void CellWindow::reset(const int &m)
{
    mode = m;
    cellName->setText("");
    if (mode == CellWindow::ADD_MODE){
        addConfirm->setEnabled(true);
        setConfirm->setEnabled(false);
    }else{
        addConfirm->setEnabled(false);
        addConfirm->setEnabled(true);
    }
}

void CellWindow::initObj()
{
    layerLabel = new QLabel("Layer:",this);
    cellLabel = new QLabel("Cell Name",this);
    pointLabel = new QLabel("Point List:",this);

    layerBox = new QComboBox(this);
    cellName = new QLineEdit(this);
    pointView = new QListView(this);

    addConfirm = new QPushButton("&Add",this);
    setConfirm = new QPushButton("&Set",this);
    cancel = new QPushButton("&Cancel",this);

    layout = new QGridLayout(this);
    layout->addWidget(layerLabel,0,0,1,1);
    layout->addWidget(layerBox,1,0,1,1);
    layout->addWidget(cellLabel,2,0,1,1);
    layout->addWidget(cellName,3,0,1,1);
    layout->addWidget(pointLabel,0,2,1,1);
    layout->addWidget(pointView,1,2,4,3);

    layout->addWidget(addConfirm,5,2,1,1);
    layout->addWidget(setConfirm,5,3,1,1);
    layout->addWidget(cancel,5,4,1,1);

    this->setLayout(layout);
}
