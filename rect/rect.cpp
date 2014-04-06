#include "rect.h"

Rect::Rect() : AbstractShape()
{
    anchor = CENTER;
    width = 0;
    height = 0;
    shiftX = 0;
    shiftY = 0;

    widthPar = "";
    heightPar = "";
    shiftXPar = "";
    shiftYPar = "";

    points->append(new Point(0,0));
    points->append(new Point(0,0));
    points->append(new Point(0,0));
    points->append(new Point(0,0));
}

Rect::Rect(Rect *src)
{
    anchor = src->getAnchor();
    width = src->getWidth();
    height = src->getHeight();
    shiftX = src->getShiftX();
    shiftY = src->getShiftY();
    shiftXPar = src->getShiftXPar();
    shiftYPar = src->getShiftYPar();

}

Rect::~Rect()
{

}

QGridLayout *Rect::getQGridLayout()
{
    if (!isSet){
        layout->addWidget(paraLabel,0,2);
        layout->addWidget(widthLabel,1,0);
        layout->addWidget(widthEdit,2,0);
        layout->addWidget(widthParEdit,2,2);
        layout->addWidget(heightLabel,3,0);
        layout->addWidget(heightEdit,4,0);
        layout->addWidget(heightParEdit,4,2);
        layout->addWidget(shiftXLabel,5,0);
        layout->addWidget(shiftXEdit,6,0);
        layout->addWidget(shiftXParEdit,6,2);
        layout->addWidget(shiftYLabel,7,0);
        layout->addWidget(shiftYEdit,8,0);
        layout->addWidget(shiftYParEdit,8,2);
        isSet = true;
    }
    widthEdit->setText(QString::number(getWidth()));
    widthParEdit->setText(QString(getWidthPar()));
    heightEdit->setText(QString::number(getWidth()));
    heightParEdit->setText(QString(getHeightPar()));
    shiftXEdit->setText(QString::number(getWidth()));
    shiftXParEdit->setText(QString(getShiftXPar()));
    shiftYEdit->setText(QString::number(getWidth()));
    shiftYParEdit->setText(QString(getShiftYPar()));
    return layout;
}

Cell *Rect::createCell()
{
    return new Rect();
}

bool Rect::applySetting()
{
    return true;
}

BBox *Rect::getBBox() const
{
    BBox *bBox = new BBox();
    bBox->left = points->at(0)->x;
    bBox->top = points->at(1)->y;
    bBox->right = points->at(2)->x;
    bBox->bottom = points->at(3)->y;
    return bBox;
}

QString Rect::getType() const
{
    return typeName;
}

int Rect::getAnchor() const
{
    return anchor;
}

bool Rect::move(double x, double y)
{
    shiftX += x;
    shiftY += y;

    if(points){
        foreach(Point *p, *points){
            p->x += x;
            p->y += y;
        }
        return true;
    }
    return false;
}

bool Rect::translate(double x, double y)
{
    move(x,y);

    if (childCells){
        foreach(Cell* child, *childCells){
            static_cast<AbstractShape*>(child)->translate(x,y);
        }
    }
    return true;
}

bool Rect::changeAnchor(int ref)
{
    anchor = ref;
    return true;
}

bool Rect::shrink(double left, double top, double right, double bottom)
{
    if ((width-left-right)<=0 || (height-top-bottom) >=0)
        return false;
    width -= left+right;
    height -= top+bottom;

    if (points){
        points->at(0)->x += left;
        points->at(0)->y += bottom;
        points->at(1)->x += left;
        points->at(1)->y -= top;
        points->at(2)->x -= right;
        points->at(2)->y -= top;
        points->at(3)->x -= right;
        points->at(3)->y += bottom;
        return true;
    }
    return false;
}

bool Rect::expand(double left, double top, double right, double bottom)
{
    return shrink(-left,-top,-right,-bottom);
}

bool Rect::copy(AbstractShape *shape)
{
    if (compare(shape)){
        Rect *src = static_cast<Rect*>(shape);
        layer = src->getLayer();
        anchor = src->getAnchor();
        width = src->getWidth();
        widthPar = src->getWidthPar();
        height = src->getHeight();
        heightPar = src->getHeightPar();
        shiftX = src->getShiftX();
        shiftXPar = src->getShiftXPar();
        shiftY = src->getShiftY();
        shiftYPar = src->getShiftYPar();
        points->clear();
        foreach(Point* p, *(src->getPoint())){
            points->append(new Point(*p));
        }
        return true;
    }
    return false;
}

bool Rect::compare(AbstractShape *shape)
{
    if (shape)
        if (typeName == shape->getType())
            return true;
    return false;
}

bool Rect::overlap(AbstractShape *shape)
{
    Q_UNUSED(shape);
    return false;
}

double Rect::getWidth() const
{
    return width;
}

double Rect::getHeight() const
{
    return height;
}

double Rect::getShiftX() const
{
    return shiftX;
}

double Rect::getShiftY() const
{
    return shiftY;
}

QString Rect::getWidthPar() const
{
    return widthPar;
}

QString Rect::getHeightPar() const
{
    return heightPar;
}

QString Rect::getShiftXPar() const
{
    return shiftXPar;
}

QString Rect::getShiftYPar() const
{
    return shiftYPar;
}

QList<Point *> *Rect::getPoints() const
{
    return points;
}

void Rect::onCreate()
{

}

void Rect::onSet()
{

}

QString Rect::typeName = "Rect";
QWidget* Rect::settingPad = new QWidget();
QGridLayout* Rect::layout = new QGridLayout();

QLabel* Rect::widthLabel = new QLabel("Width:");
QLabel* Rect::heightLabel = new QLabel("Height:");
QLabel* Rect::paraLabel = new QLabel("Parameterized?");
QLabel* Rect::shiftXLabel = new QLabel("X shift:");
QLabel* Rect::shiftYLabel = new QLabel("Y shift:");
QLineEdit* Rect::widthEdit = new QLineEdit();
QLineEdit* Rect::heightEdit = new QLineEdit();
QLineEdit* Rect::shiftXEdit = new QLineEdit();
QLineEdit* Rect::shiftYEdit = new QLineEdit();
QLineEdit* Rect::widthParEdit = new QLineEdit();
QLineEdit* Rect::heightParEdit = new QLineEdit();
QLineEdit* Rect::shiftXParEdit = new QLineEdit();
QLineEdit* Rect::shiftYParEdit = new QLineEdit();

bool Rect::isSet = false;
