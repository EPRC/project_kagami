#include "layer.h"

Layer::Layer()
{
    this->color = Qt::blue;
    this->num = 1;
    this->name = QString("New Layer");
    this->depth = 0.1;
}

Layer::~Layer()
{
}

QColor Layer::getColor() const
{
    return this->color;
}

QVariant Layer::getName() const
{
    return QVariant(this->name);
}

QVariant Layer::getNum() const
{
    return QVariant(this->num);
}

QVariant Layer::getDepth() const
{
    return QVariant(this->depth);
}

bool Layer::setColor(const QColor &colorp)
{
    if (color.isValid()){
        this->color = colorp;
        return true;
    }
    return false;
}

bool Layer::setColor(const QVariant &colorp)
{
    if (color.isValid()){
        this->color = colorp.value<QColor>();
        return true;
    }
    return false;
}

bool Layer::setName(const QVariant &namep)
{
    if (namep.isValid()){
        this->name = QString(namep.toString());
        return true;
    }
    return false;
}

bool Layer::setName(const QString &namep)
{
    if (!namep.isNull()){
        this->name = namep;
        return true;
    }
    return false;
}

bool Layer::setNum(const QVariant &nump)
{
    bool result;
    nump.toInt(&result);
    if (result){
        this->num = nump.toInt();
        return true;
    }
    return false;
}

bool Layer::setNum(const int &nump)
{
    this->num = nump;
    return true;
}

bool Layer::setDepth(const QVariant &depthp)
{
    bool result;
    depthp.toDouble(&result);
    if (result){
        this->depth = depthp.toDouble();
        return true;
    }
    return false;
}

bool Layer::setDepth(const double &depthp)
{
    this->depth = depthp;
    return true;
}



