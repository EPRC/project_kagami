#include "layermanger.h"

LayerManager::LayerManager(QWidget *parent) :
    QDialog(parent)
{
    label_name = new QLabel(QString("Name"),this);
    label_color = new QLabel(QString("Color"),this);
    label_num = new QLabel(QString("ID"),this);
    label_depth = new QLabel(QString("Depth"),this);
    color = new QComboBox(this);
    num = new QSpinBox(this);
    name = new QLineEdit(QString("[New Layer]"),this);
    depth = new QLineEdit(QString("0"),this);

    confirm = new QPushButton(QString("Confirm"),this);
    cancel = new QPushButton(QString("Cancel"),this);

    color->addItem("red");
    color->addItem("green");
    color->addItem("blue");
    color->addItem("black");
    color->addItem("white");

    num->setValue(1);
    num->setMinimum(1);

    lyt = new QGridLayout(this);
    lyt->addWidget(label_color,0,0,1,1);
    lyt->addWidget(color,1,0,1,1);
    lyt->addWidget(label_num,0,1,1,1);
    lyt->addWidget(num,1,1,1,1);
    lyt->addWidget(label_name,0,2,1,1);
    lyt->addWidget(name,1,2,1,1);
    lyt->addWidget(label_depth,0,3,1,1);
    lyt->addWidget(depth,1,3,1,1);

    lyt->addWidget(confirm,2,2,1,1);
    lyt->addWidget(cancel,2,3,1,1);

    this->setLayout(lyt);

    connect(confirm,SIGNAL(clicked()),this,SLOT(onConfirmClick()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(onCancelClick()));
}

LayerManager::~LayerManager()
{

}

QColor LayerManager::getColor() const
{
    return QColor(color->currentText());
}

int LayerManager::getNum() const
{
    return num->value();
}

QString LayerManager::getName() const
{
    return name->text();
}

double LayerManager::getDepth() const
{
    return depth->text().toDouble();
}

void LayerManager::reset()
{
    name->setText(QString("[New Layer]"));
    depth->setText(QString("0"));
    num->setValue(1);
}

void LayerManager::onConfirmClick()
{
    bool result;

    depth->text().toDouble(&result);
    if (result){
        emit addLayer(getColor(),getNum(),getName(),getDepth());
    }
    else{
        QMessageBox *box = new QMessageBox();
        box->setText(QString("Invalid input!"));
        box->setStandardButtons(QMessageBox::Ok);
        box->exec();
    }
}

void LayerManager::onCancelClick()
{
    this->reset();
    this->close();
}

void LayerManager::addLayerSucceed()
{
    this->reset();
    this->close();
}

void LayerManager::addLayerFail(const int &failureCode)
{
    QMessageBox *box = new QMessageBox();
    switch(failureCode){
        case LayerManager::NUM_EXIST:
            box->setText(QString("The Layer ID is existed."));
            break;
        case LayerManager::INFO_MISS:
            box->setText(QString("Infomation is missed."));
            break;
        default:
            box->setText(QString("Add Layer failed"));
    }
    box->setStandardButtons(QMessageBox::Ok);
    box->exec();
}
